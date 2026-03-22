#include <iostream>
using namespace std;

int h, w;
int grid[41][41];
int vis[41][41] = {0};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < h && y < w;
}

int maxPath(int x, int y) {
    int pathlen;
    int maxpathlen = 0;
    int nextx, nexty;
    cout << "kiosk: " << grid[x][y] << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            pathlen = 0;
            if (i == x && j == y) continue;
            cout << "starting from: " << grid[x][y] << ", going to: " << grid[i][j] << endl;
            int fx = x, fy = y;
            for (int i = 0; i < 41; i++) {
                for (int j = 0; j < 41; j++) {
                    vis[i][j] = 0;
                }
            }
            while (fx != i && fy != j) {
                for (int d = 0; d < 4; d++) {
                    int diff = INT_MAX;
                    int newx = dx[d] + fx;
                    int newy = dy[d] + fy;
                    if (!valid(newx, newy)) continue;
                    if (abs(grid[fx][fy] - grid[newx][newy]) < diff) {
                        nextx = newx;
                        nexty = newy;
                        diff = abs(grid[fx][fy] - grid[newx][newy]);
                        cout << diff << " = " << grid[x][y] << " - " << grid[newx][newy] << endl;
                    }
                }
                fx = nextx;
                fy = nexty;
                cout << grid[fx][fy] << endl;
                if (vis[fx][fy] == 1) return 0;
                else vis[fx][fy] = 1;
                pathlen++;
                cout << "pathlen: " << pathlen << endl;
            }
            maxpathlen = max(maxpathlen, pathlen);
        }
    }
    return maxpathlen;
}

int main() {
    int ans = 0;
    int optPos;
    int c = 0;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int length = maxPath(i, j);
            cout << grid[i][j] << "'s length: " << length << endl;
            if (length == 0) {
                c++;
                continue;
            }
            if (length < ans) {
                ans = length;
                int optPos = grid[i][j];
            }
        }
    }
    if (c != h*w) cout << optPos << " " << ans << endl;
    else cout << "impossible" << endl;
}