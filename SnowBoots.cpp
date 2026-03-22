#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int N, B, n, e;
    int ans = 0;
    vector<int> snow;
    queue<pair<int, int> > boots;
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> n;
        snow.push_back(n);
    }
    for (int i = 0; i < B; i++) {
        cin >> n >> e;
        boots.push(make_pair(n, e));
    }
    int tile = 0;
    int maxtile = 0;
    bool moved = false;
    while (!boots.empty() && tile < N-1) {
        if (!moved) {
            boots.pop();
            ans++;
            while (boots.front().first < snow[tile]) {
                boots.pop();
                ans++;
            }
        }
        moved = false;
        maxtile = 0;
        //cout << tile << endl;
        for (int d = 1; d <= min(N-1-boots.front().second, boots.front().second); d++) {
            if (snow[tile+d] <= boots.front().first) {
                maxtile = max(maxtile, d);
                moved = true;
            }
        }
        tile += maxtile;
    }
    cout << ans << endl;
}