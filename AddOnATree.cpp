#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, u, v;
    cin >> n;
    vector<int> adj[n+1];
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int node = 0;
    int leaf = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 2) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}