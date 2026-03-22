#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int solve(int n, int m, vector<int>& monsters, multiset<pair<int, int> >& heroes) {
    int monster = monsters.size() - 1;
    int ans = 0;
    while (monster >= 0) {
        bool go = true;
        pair<int, int> bestHero;
        for (auto i = heroes.rbegin(); i != heroes.rend(); i++) {
            //cout << "Hero: " << (*i).first << ", " << (*i).second << endl;
            if ((*i).first < monsters[monster]) break;
            for (int j = 0; j < (*i).second; j++) {
                if (monsters[monster - j] > (*i).first) {
                    go = false;
                    break;
                }
            }
            if (bestHero.second < (*i).second && go) {
                bestHero = *i;
            }
        }
        ans++;
        monster -= bestHero.second;
    }
    return ans;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    vector<int> monsters;
    multiset<pair<int, int> > heroes;
    int t, n, m, a, b;
    cin >> t;
    for (int z = 0; z < t; z++) {
        monsters.clear();
        heroes.clear();
        int maxMonster = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            maxMonster = max(maxMonster, a);
            monsters.push_back(a);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            heroes.insert(make_pair(a, b));
        }
        auto it = heroes.rbegin();
        pair<int, int> hi = *it;
        //cout << "maxMonster" << maxMonster << endl;
        if (maxMonster > hi.first) {
            cout << "-1" << "\n";
        }
        else cout << solve(n, m, monsters, heroes) << "\n";
    }
}