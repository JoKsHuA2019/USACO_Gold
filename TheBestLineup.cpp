#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        int dp[N];
        fill_n(dp, N, 1);
        int indexes[N];
        fill_n(indexes, N, -1);
        int nums[N];
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        for (int i = 1; i < N; i++) {
            int maxSequence = 0;
            int maxIndex = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i] && maxSequence < dp[j]) {
                    maxSequence = dp[j];
                    maxIndex = j;
                }
            }
            dp[i] += maxSequence;
            indexes[i] = maxIndex;
        }
        int starting = 0;
        int larg = 0;
        int wee = 0;
        for (int i = 0; i < N; i++) {
            if (dp[i] > larg) {
                larg = dp[i];
                starting = i;
                wee = nums[i];
            }
            else if (dp[i] == larg) {
                if (wee < nums[i]) {
                    larg = dp[i];
                    starting = i;
                    wee = nums[i];
                }
            }
        }
        vector<int> cows;
        while (starting >= -1) {
            cows.push_back(nums[starting]);
            nums[starting] = 0;
            if (indexes[starting] == -1) {
                break;
            }
            starting = indexes[starting];
        }
        int largNum = 0;
        for (int i = 0; i < N; i++) {
            largNum = max(largNum, nums[i]);
        }
        int i = 0;
        reverse(cows.begin(), cows.end());
        while (i < cows.size() && largNum < cows[i]) i++;
        for (int j = 0; j < cows.size(); j++) {
            if (j == i) cout << largNum << " ";
            if (j == cows.size()-1) cout << cows[j];
            else cout << cows[j] << " ";
        }
        cout << "\n";
    }
}