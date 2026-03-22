#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

long long solve(vector<int>& goodsRem, int n, int k, long long ans) {
    long long add = 0;
    // cout << "ans: " << ans << endl;
    int l = 0, r = n-1;
    int pairs = 0, diff;
    while (l < n && r > l) {
        // cout << "l: " << l << ", r: " << r << endl;
        if (goodsRem[l] + goodsRem[r] == k) {
            ans++;
            l++; r--;
        }
        else if (goodsRem[l] + goodsRem[r] > k) {
            ans++;
            l++; r--;
        }
        else if (goodsRem[l] + goodsRem[r] < k) {
            l++;
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> goodsRemainder;
    int T, n, k, a;
    cin >> T;
    long long sum;
    for (int z = 0; z < T; z++) {
        cin >> n >> k;
        sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            goodsRemainder.push_back(a%k);
            ans += a/k;
        }
        sort(goodsRemainder.begin(), goodsRemainder.end());
        //cout << "totalSum: " << sum << endl;
        cout << solve(goodsRemainder, n, k, ans) << "\n";
        goodsRemainder.clear();
    }
    return 0;
}