#include <iostream>
#include <climits>
using namespace std;

int xm[4] = {0, 1, 0, -1}, ym[4] = {1, 0, -1, 0}, R, C;

int longest_path = 0;
int graph[105][105];
int start_x, start_y, end_x, end_y;

bool check(int prev_x, int prev_y, int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C && graph[x][y] < graph[prev_x][prev_y];
}

int dfs(int x, int y, int l) {
    for (int i = 0; i < 4; i++) {
        if (check(x, y, x + xm[i], y+ym[i])) {
            longest_path = max(longest_path, dfs(x+xm[i], y+ym[i], l+1));
        }
    }
    return l;
}

int main() {
    cin >> R >> C;
    int small = INT_MAX, big = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
            if (graph[i][j] > big) {
                start_x = i;
                start_y = j;
                big = graph[i][j];
            }
            if (graph[i][j] < small) {
                end_x = i;
                end_y = j;
                small = graph[i][j];
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dfs(i, j, 1);
        }
    }
    cout << longest_path << "\n";
}