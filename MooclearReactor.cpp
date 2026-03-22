#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Edge {
    int to;
    int weight;
};

vector<ll> l, r;
vector<vector<Edge>> adj;
vector<int> visited;
vector<ll> k_val;
vector<int> color;  

void solve() {
    int N, M;
    cin >> N >> M ;

    l.resize(N + 1);
    r.resize(N + 1);
    adj.assign(N + 1, vector<Edge>());

    //making everything resit
    visited.assign(N + 1, 0);
    k_val.assign(N + 1, 0);
    color.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> l[i];
    for (int i = 1; i <= N; i++) cin >> r[i];

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bool possible = true;
    ll total_ans = 0;

    //bfs now
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        vector<int> nodes;
        vector<int> q;
        visited[i] = 1;
        q.push_back(i);
        nodes.push_back(i);
        
        k_val[i] = 0;
        color[i] = 0;

        bool fixed = false;
        ll fixed_value = 0;
        bool comp_possible = true;
        
        int head = 0;
        while(head < q.size()){
            int u = q[head++];

            for(auto &e : adj[u]){

                int v_node = e.to;
                int w = e.weight;
                
                if(visited[v_node]){
                    if(color[u] != color[v_node]){
                        if(k_val[u] + k_val[v_node] != w) {
                            comp_possible = false;
                        }
                    }
                    //mmm
                    
                    else {

                        ll rhs;
                        if(color[u] == 0) rhs = (ll)w - k_val[u] - k_val[v_node]; 

                        else rhs = k_val[u] + k_val[v_node] - (ll)w;
                        
                        if(rhs % 2 != 0) {

                            comp_possible = false;
                        } 
                        else {
                            ll candiidate = rhs / 2;
                            if(fixed && fixed_value != candiidate) {

                                comp_possible = false;
                            }
                            fixed = true;
                            fixed_value = candiidate;
                        }
                    }
                }


                else {
                    visited[v_node] = 1;
                    color[v_node] = 1 - color[u];
                    k_val[v_node] = (ll)w - k_val[u];
                    nodes.push_back(v_node);
                    q.push_back(v_node);
                }
            }
        }

        if(!comp_possible) {
            possible = false;

            break;
        }


        // what if we could use a bipartite graph to represent the sum in bewteen each rod as the edge
        if(fixed){

            for(int u : nodes){
                ll val;
                if(color[u] == 0) val = k_val[u] + fixed_value;
                else val = k_val[u] - fixed_value;
                
                if(val >= l[u] && val <= r[u]) total_ans++;
            }
        }
        else {
            vector<pair<ll, int>> events;

            //hmm

            for(int u : nodes){

                ll L, R;
                if(color[u] == 0){



                    L = l[u] - k_val[u];
                    R = r[u] - k_val[u];
                }

                else {
                    L = k_val[u] - r[u];
                    R = k_val[u] - l[u];
                }
                
                if(L <= R){
                    events.push_back({L, 1});
                    events.push_back({R + 1, -1});
                }
            }
            
            sort(events.begin(), events.end()); //wewewewe i dont know whats going on <algorithms> is so useful im crashing out
            
            int max_c = 0, cur_c = 0;
            for(auto &ev : events){
                cur_c += ev.second;
                if(cur_c > max_c) max_c = cur_c;
            }
            total_ans += max_c;
        }
    }

    if(possible) cout << total_ans << "\n";
    else cout << "-1" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}