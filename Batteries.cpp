#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        bool done = false;

        for (int d = 1; d < n && !done; d++) {
            for (int j = 1; j <= n && !done; j++) {
                int k = j + d;
                if (k > n) k -= n;

                cout << j << " " << k << endl;
                cout.flush();

                int x;
                if (!(cin >> x)) return 0;
                if (x == -1) return 0;
                if (x == 1) {
                    done = true;
                }
            }
        }
    }

    return 0;
}
