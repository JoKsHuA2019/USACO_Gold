#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(int left, int right, int target) {
    int l = left, r = right, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (target > mid) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N, n, ans = 0;
    int vis[50001] = {0};
    cin >> N;
    vector<int> Elsie1, Elsie2, Bessie;
    for (int i = 0; i < N; i++) {
        cin >> n;
        if (i < N/2) Elsie1.push_back(n);
        else Elsie2.push_back(n);
    }
    for (int i = 1; i <= 2*N; i++) {
        if (count(Elsie1.begin(), Elsie1.end(), i) == 0 && count(Elsie2.begin(), Elsie2.end(), i) == 0) Bessie.push_back(i);
    }

    for (int i = 0; i < Elsie1.size(); i++) {
        int maxNum = 50022;
        int minNum = 50022;
        for (int j = Bessie.size()/2; j <= Bessie.size(); j++) {
            if (Bessie[j] < minNum && vis[Bessie[j]] == 0) {
                minNum = Bessie[j];
                break;
            }
            //cout << "comparing " << Elsie1[i] << " and " << Bessie[j] << endl;
        }
        maxNum = search(Bessie.size()/2, Bessie.size(), Elsie1[i]);
        //cout << maxNum << endl;
        if (maxNum == 50022) {
            vis[minNum] = 1;
        }
        else {
            vis[maxNum] = 1;
            ans++;
        }
        vis[Elsie1[i]] = 1;
    }


















    
    for (int i = 0; i < Elsie1.size(); i++) {
        int maxNum = 50022;
        int minNum = 50022;
        for (int j = Bessie.size()/2; j <= Bessie.size(); j++) {
            if (Bessie[j] < minNum && vis[Bessie[j]] == 0) {
                minNum = Bessie[j];
            }
            if (Elsie1[i] < Bessie[j] && vis[Bessie[j]] == 0 && vis[Elsie1[i]] == 0) maxNum = min(maxNum, Bessie[j]);
            //cout << "comparing " << Elsie1[i] << " and " << Bessie[j] << endl;
        }
        //cout << maxNum << endl;
        if (maxNum == 50022) {
            vis[minNum] = 1;
        }
        else {
            vis[maxNum] = 1;
            ans++;
        }
        vis[Elsie1[i]] = 1;
    }

    for (int i = 0; i < Elsie2.size(); i++) {
        int maxNum = 0;
        int minNum = 0;
        for (int j = 0; j < Bessie.size()/2; j++) {
            if (Bessie[j] > minNum && vis[Bessie[j]] == 0) {
                minNum = Bessie[j];
            }
            if (Elsie2[i] > Bessie[j] && vis[Bessie[j]] == 0 && vis[Elsie2[i]] == 0) maxNum = max(maxNum, Bessie[j]);
            //cout << "comparing " << Elsie2[i] << " and " << Bessie[j] << endl;
        }
        //cout << maxNum << endl;
        if (maxNum == 0) {
            vis[minNum] = 1;
        }
        else {
            vis[maxNum] = 1;
            ans++;
        }
        vis[Elsie2[i]] = 1;
    }
    // for (int i = 0; i < Bessie.size(); i++) {
    //     cout << Bessie[i] << " ";
    // }
    cout << ans << endl;
    return 0;
}