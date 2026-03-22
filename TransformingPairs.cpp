#include <iostream>
using namespace std;

bool check(int m) {
    
}

int main() {
    int T;
    long long a, b, c, d;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        long long l = 0, r = max(a, max(b, max(c, d))), m;
        while (l < r) {
            m = l + (l-r+1)/2;
            if (check(m)) r = m;
            else l = m + 1;
        }
    }
    return 0;
}