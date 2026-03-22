#include <iostream>
#include <vector>
using namespace std;

bool V[13] = {false}, D_R[50] = {false}, D_L[50] = {false};
bool vis[13][13] = {false};
int n, ans = 0;


void dfs(int row) {
    if (row == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!V[i] && !D_R[i+row] && !D_L[i-row+n]) {
            V[i] = true; D_R[i+row] = true; D_L[i-row+n] = true;
            dfs(row+1);
            V[i] = false; D_R[i+row] = false; D_L[i-row+n] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans << "\n";
}