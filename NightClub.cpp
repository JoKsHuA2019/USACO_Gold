#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    long long K, F, n, e;
    long long ans = 0, latest = 0;
    vector<long long> t;
    multimap<long long, long long> x;
    cin >> K >> F;
    for (int z = 0; z < K; z++) {
        cin >> n;
        t.push_back(n);
    }
    for (int z = 0; z < F; z++) {
        cin >> n >> e;
        x.insert(make_pair(e, n));
    }
    sort(t.begin(), t.end());
    for (auto const& element : x) {
        int i = 0;
        while (i < t.size() && t[i] < element.second) {
            i++;
        }
        if (i >= t.size()) continue;
        if (t[i] <= element.first) {
            ans++;
            latest = max(latest, t[i]);
            t.erase(t.begin() + i);
        }
    }
    cout << ans << " " << latest << endl;
}