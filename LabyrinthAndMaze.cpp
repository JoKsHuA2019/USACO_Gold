#include <iostream>
#include <vector>
using namespace std;

int xm[4] = {0, 1, 0, -1}, ym[4] = {1, 0, -1, 0};

int graph[51][51];
int vis[51][51] = {false};
int n, ans = 0;
int lengths[150];

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && graph[x][y] == 0;
}

void floodfill(int x, int y, int length) {
    if (x == n-1 && y == n-1) {
        lengths[length]++;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (check(x + xm[i], y + ym[i])) {
            vis[x][y] = true;
            floodfill(x+xm[i], y+ym[i], length+1);
            vis[x][y] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    floodfill(0, 0, 1);
    for (int i = 0; i < 150; i++) {
        if (lengths[i] != 0) {
            cout << lengths[i] << "\n" << i;
            return 0;
        }
    }
}