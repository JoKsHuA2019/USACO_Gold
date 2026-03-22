#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, R, C, counter = 2;
int vis[301][301] = {0};
char grid[301][301];
int fx, fy;
int ex, ey;

// int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

// bool valid(int x, int y, string s) {
//     return x >= 0 && y >= 0 && x < R && y < C && vis[x][y] == 0 && grid[x][y] == s[counter-1];
// }

// void bfs(int r, int c, int x, int y, string s) {
//     queue<pair<int, pair<int, int> > > q;
//     q.push(make_pair(x, make_pair(y, 1)));
//     vis[x][y] = 1;
//     counter = 2;
//     while (!q.empty()) {
//         auto pair = q.front();
//         q.pop();
//         counter = pair.second.second + 1;
//         for (int i = 0; i < 4; i++) {
//             int newx = dx[i] + pair.first;
//             int newy = dy[i] + pair.second.first;
//             if (valid(newx, newy, s)) {
//                 //cout << newx << " " << newy << endl;
//                 q.push(make_pair(newx, make_pair(newy, counter)));
//                 vis[newx][newy] = counter;
//                 ex = newx;
//                 ey = newy;
//             }
//         }
//         counter++;
//         if (counter == s.length()+1) {
//             return;
//         }
//     }
// }

void dfs(int x, int y, string s) {
    if (counter == s.length()+1) {
        return;
    }
    vis[x][y] = counter;
    for (int i = 0; i < 4; i++) {
        if (valid(newx, newy, s)) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            dfs(newx, newy, s);
            vis[newx][newy] = 1;
        }
        
    }
    
}

int main() {
    string s;
    cin >> T;
    char n;
    bool solved;
    for (int z = 0; z < T; z++) {
        cin >> s;
        cin >> R >> C;
        counter = 2;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> n;
                grid[i][j] = n;
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == s[0]) {
                    // cout << grid[i][j] << " " << s[0] << endl;
                    //cout << i << " " << j << endl;
                    solved = false;
                    for (int i = 0; i < R; i++) {
                        for (int j = 0; j < C; j++) {
                            //cout << vis[i][j];
                            vis[i][j] = 0;
                            fx = i;
                            fy = j;
                        }
                        //cout << endl;
                    }
                    bfs(R, C, i, j, s);
                    if (counter == s.length() + 1) {
                        solved = true;
                        break;
                    }
                }
            }
            if (solved) break;
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (vis[i][j] == 0) cout << "#";
                else {
                    int c = 0;
                    for (int d = 0; d < 4; d++) {
                        int newx = i + dx[d];
                        int newy = j + dy[d];
                        if (vis[newx][newy] > 0) {
                            c++;
                        }
                    }
                    if (c == 1 && ((fx == i && fy == j) || (ex == i && ey == i))) {
                        cout << s[vis[i][j]-1];
                    }
                    if (c >= 2) {
                        cout << s[vis[i][j]-1];
                    }
                }
                //cout << vis[i][j];
            }
            cout << endl;
        }
    }
}