#include <iostream>
#include <queue>
#include <iomanip>
#include <climits>
#include <algorithm>
using namespace std;

#define tuples tuple<int, int, int>

int n, m, x, y;
int grid[401][401];
bool vis[401][401];

int xx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, yy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

void bfs() {
    queue<tuples> q;
    tuples start = {x-1, y-1, 0};
    q.push(start);
    vis[x-1][y-1] = true;

    while (!q.empty()) {
        tuples front = q.front();
        q.pop();

        grid[get<0>(front)][get<1>(front)] = get<2>(front);

        for (int i = 0; i < 8; i++) {
            int newx = get<0>(front) + xx[i];
            int newy = get<1>(front) + yy[i];
            if (check(newx, newy)) {
                tuples newValue = {newx, newy, get<2>(front)+1};
                vis[newx][newy] = true;
                q.push(newValue);
            }
        }
    }
}

int main() {
    fill_n(&grid[0][0], 401*401, -1);
    cin >> n >> m >> x >> y;
    
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << right << grid[i][j] << " ";
        }
        cout << "\n";
    }
}