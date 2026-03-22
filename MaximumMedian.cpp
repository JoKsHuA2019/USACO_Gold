#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
int n, k;

bool check(int m) {
    long long sum = 0;
    for (int i = (n-1)/2; i < n; i++) {
        sum += max(0, m - a[i]);
    }
    //cout << sum << endl;
    return sum <= k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int l = 0, r = 2e9, m;
    while (l < r) {
        //cout << "l: " << l << " r: " << r << endl;
        m = l + (r-l+1)/2;
        if (check(m)) {
            l = m;
        }
        else r = m - 1;
    }
    cout << l;
    return 0;
}