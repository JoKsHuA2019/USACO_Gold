#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> stairs;
    stairs.resize(n+5, 0);
    stairs[0] = 1;
    stairs[1] = 1;
    stairs[2] = 2;
    for (int i = 3; i <= n; i++) {
        stairs[i] = (stairs[i-1] + stairs[i-2] + stairs[i-3]) % 998244353;
    }
    cout << stairs[n] << "\n";
}