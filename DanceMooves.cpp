#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int n, k, a, b;
    cin >> k;
    vector<pair<int, int> > moves(k);
    vector<int> cows(n);
    vector<set<int> > vis;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        moves.push_back(make_pair(a, b));
    }
    for (int i = 0; i < n; i++) {
        cows.push_back(i);
    }
    // Simulate the swapping
    for (int i = 0; i < k; i++) {
        swap(cows.begin() + moves[i].first, cows.begin() + moves[i].second);
        vis[moves[i].first].insert(moves[i].second);
        vis[moves[i].second].insert(moves[i].first);
    }
    vector<int> newPositions;
    while (!is_sorted(newPositions.begin(), newPositions.end())) {
        for (int i = 0; i < n; i++) {
            newPositions[i] = cows[cows[i]];

        }   
    }

    // 
}