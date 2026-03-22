#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T, N, K, n;
    vector<int> a;
    cin >> T;
    for (int z = 0; z < T; z++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> n;
            a.push_back(n);
        }
        sort(a.begin(), a.end());
        int i = 0, j = 1;
        int diff = 0;
        while (i < N) {
            while (j < N && a[j] - a[i] <= K) j++;
            diff = max(j - i, diff);
            i++;
        }
        cout << N - diff << endl;
        a.clear();
    }
}