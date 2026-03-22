#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

void solve() {
    int n, k, u, v;
    cin >> n >> k;
    vector<int> vis(n+1, -1);
    vector<int> adj[n+1];
    queue<int> q;
    for (int i = 0; i < k; i++) {
            cin >> u;
            q.push(u);
            vis[u] = 0;
    }
    q.push(1);
    vis[1] = 1;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        //cout << "currNode: " << node.first << endl;
        for (auto i : adj[node]) {
            if (vis[i] == -1) {
                q.push(i);
                vis[i] = vis[node];
                //maxDistance = max(maxDistance, node.second+1);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (adj[i].size() == 1 && vis[i] == 1) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t, u, v;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}