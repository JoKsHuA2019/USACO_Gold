#include <iostream>
#include <vector>
using namespace std;

int vis[100001];
vector<int> adj[n];
vector<int> indices;
int target;

void dfs(int node, int counter) {
    if () {
        // if total nodes part of set to be visited is met
        // return
    }
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
        if (vis[node] == 0) {
            dfs(adj[node], counter+1);
        }
    }
    vis[node] = 0;
}

void solve() {
    dfs(indices[0], 1);
    for (int i = 0; i < indices.size(); i++) {
        int totalNodes = 0;
        for (int j = 0; j < indices[i]; j++) {
            if (vis[indices[i][j]] == 1) {
                totalNodes++;
            }
        }
        if (totalNodes > 2) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n, u, v, q, k, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    while (q--) {
        memset(vis, 0);
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> p;
            indices.push_back(p);
        }
        solve();
    }
}