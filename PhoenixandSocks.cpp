#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

set<int> leftSocks, rightSocks;

void solve(int n, int l, int r) {
    leftSocks.clear();
    rightSocks.clear();
    int cl[200001] = {0};
    int cr[200001] = {0};
    int sock, ans = 0;
    int maxSock = 0;
    for (int i = 0; i < l; i++) {
        cin >> sock;
        leftSocks.insert(sock);
        cl[sock]++;
        maxSock = max(maxSock, sock);
    }
    for (int i = 0; i < r; i++) {
        cin >> sock;
        rightSocks.insert(sock);
        cr[sock]++;
        maxSock = max(maxSock, sock);
    }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cl[leftSocks.begin(), i] << " ";
    // }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cr[rightSocks.begin(), i] << " ";
    // }
    // cout << endl;
    //cout << "1" << endl;
    for (int i = 0; i <= maxSock; i++) {
        if (cl[i] > 0 && cr[i] > 0) {
            int subtract = min(cl[i], cr[i]);
            cl[i] -= subtract;
            cr[i] -= subtract;
        }
    }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cl[leftSocks.begin(), i] << " ";
    // }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cr[rightSocks.begin(), i] << " ";
    // }
    // cout << endl;
    //cout << "2" << endl;
    int swaps = abs(int(r-n/2));
    ans += abs(int(r-n/2));
    for (int i = 0; i <= maxSock; i++) {
        if (cl[i] > 1 && cr[i] == 0 && swaps != 0 && l > r) {
            cr[i] += cl[i]/2;
            cl[i] -= cl[i]/2;
            swaps--;
            l--;
            r++;
        }
        else if (cr[i] > 1 && cl[i] == 0 && swaps != 0 && l < r) {
            cl[i] += cr[i]/2;
            cr[i] -= cr[i]/2;
            swaps--;
            r--;
            l++;
        }
        if (swaps == 0) break;
    }
    
    for (int i = 0; i <= maxSock; i++) {
        if (cl[i] > 0 && cr[i] > 0) {
            int subtract = min(cl[i], cr[i]);
            cl[i] -= subtract;
            cr[i] -= subtract;
        }
    }

    for (int i = 0; i <= maxSock; i++) {
        if (cl[i] > 0 && cr[i] == 0 && swaps != 0 && l > r) {
            cr[i] += cl[i];
            cl[i] -= cl[i];
            swaps--;
            l--;
            r++;
        }
        else if (cr[i] > 0 && cl[i] == 0 && swaps != 0 && l < r) {
            cl[i] += cr[i];
            cr[i] -= cr[i];
            swaps--;
            r--;
            l++;
        }
        if (swaps == 0) break;
    }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cl[leftSocks.begin(), i] << " ";
    // }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cr[rightSocks.begin(), i] << " ";
    // }
    //cout << endl;
    //cout << "3" << endl;
    for (int i = 0; i <= maxSock; i++) {
        if (cl[i] > 0 && cr[i] > 0) {
            int subtract = min(cl[i], cr[i]);
            cl[i] -= subtract;
            cr[i] -= subtract;
        }
    }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cl[leftSocks.begin(), i] << " ";
    // }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cr[rightSocks.begin(), i] << " ";
    // }
    // cout << endl;
    //cout << "4" << endl;
    for (int i = 0; i <= maxSock; i++) {
        ans += cl[i];
    }
    // int counter = abs(l-r);
    // if (l > r) {
    //     for (int i = 0; i < l; i++) {
    //         if (cl[*next(leftSocks.begin(), i)] > 1 && counter != 0) {
    //             cr[*next(leftSocks.begin(), i)] += cl[*next(leftSocks.begin(), i)] - 1;
    //             cl[*next(leftSocks.begin(), i)] = 1;
    //             counter--;
    //         }
    //     }
    // }
    // if (r > l) {
    //     for (int i = 0; i < l; i++) {
    //         if (cl[*next(rightSocks.begin(), i)] > 1 && counter != 0) {
    //             cr[*next(rightSocks.begin(), i)] += cl[*next(rightSocks.begin(), i)] - 1;
    //             cl[*next(rightSocks.begin(), i)] = 1;
    //             counter--;
    //         }
    //     }
    // }

    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cl[leftSocks.begin(), i] << " ";
    // }
    // for (int i = 0; i <= maxSock; i++) {
    //     cout << cr[rightSocks.begin(), i] << " ";
    // }
    //cout << ans;

    // int transitionSocks = 0;
    // for (int i = 0; i <= maxSock; i++) {
    //     if (cl[i] == cr[i]) continue;
    //     ans += max(0, abs(cl[i] - cr[i]) - transitionSocks);
    //     transitionSocks = abs(cl[i] - cr[i]);
    //     //ans += cl[*next(leftSocks.begin(), i)]-1;
    // }
    
    //cout << ans;
    // for (int i = 0; i < rightSocks.size(); i++) {
    //     ans += cr[*next(rightSocks.begin(), i)]-1;
    //     //cout << cr[*next(rightSocks.begin(), i)]-1;
    // }
    cout << ans << endl;
}

int main() {
    int t, n, l, r, c;
    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n >> l >> r;
        solve(n, l, r);
    }
    return 0;
}