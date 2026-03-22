#include <iostream>
#include <climits>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

int n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
pair<int, int> start, finish;
vector<string> grid;

struct State {
    int x, y, dir, steps, length;
};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

void bfs() {
    queue<State> q;
    set<tuple<int, int, int, int>> visited;

    q.push({start.first, start.second, -1, 0, 0});
    visited.insert({start.first, start.second, -1, 0});

    while (!q.empty()) {
        State f = q.front();
        q.pop();

        if (f.x == finish.first && f.y == finish.second) {
            cout << f.length << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newx = f.x + dx[i];
            int newy = f.y + dy[i];

            if (!valid(newx, newy)) continue;

            int newDir = i;
            int newSteps = (newDir == f.dir) ? f.steps + 1 : 1;

            if (newSteps > 3) continue;

            if (!visited.count({newx, newy, newDir, newSteps})) {
                visited.insert({newx, newy, newDir, newSteps});
                q.push({newx, newy, newDir, newSteps, f.length + 1});
            }
        }
    }

    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    grid.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            }
            if (grid[i][j] == 'T') {
                finish = {i, j};
            }
        }
    }

    bfs();
    return 0;
}