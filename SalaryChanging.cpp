#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool check(long long s, int num, vector<pair<int, int> >& low) {
    int cnt = 0;
    long long sum = 0;
    vector<int> v;
    for (int i = 0; i < low.size(); i++) {
        if (num <= low[i].first) {
            sum += low[i].first;
            cnt++;
        }
        else if (num > low[i].second) {
            sum += low[i].first;
        }
        else v.push_back(low[i].first); 
    }
    int rem = max(0, (int)((low.size()+1)/2 - cnt));
    if (v.size() < rem) return false;
    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() - rem) {
            sum += v[i];
        }
        else sum += num;
    }
    // check if the salary required to satisfy this median exceeds the money provided
    //cout << "searching for: " << num << " and sum = " << sum << endl;
    return sum <= s;
}

void solve() {
    vector<pair<int, int> > low;
    int n, l, r;
    long long s, sum;
    cin >> n >> s;
    int med = (int)(n/2);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        low.push_back(make_pair(l, r));
    }
    int i = 1, j = 1e9+100, mid;
    sort(low.begin(), low.end());
    while (j - i > 1) {
        mid = (i+j)/2;
        if (check(s, mid, low)) {
            i = mid;
        }
        else {
            j = mid;
        }
    }
    cout << i;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}