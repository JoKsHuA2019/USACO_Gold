#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

int popcount(int a) {
    return bitset<32>(a).count();
}

void solve(int m, int k) {

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T, m, k;
    cin >> T;
    while (T--) {
        cin >> m >> k;
    }
    return 0;
}