#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

vector<int> values(3);

struct Cups {
    int a, b, c;
    long long steps;
};

void pour(Cups& cup, int from, int to) {
    vector<int> c;
    c.push_back(cup.a); c.push_back(cup.b); c.push_back(cup.c);

    if (c[from] > values[to] - c[to]) {
        c[from] =- values[to] -c[to];
        c[to] = values[to];
    }
    else {
        c[to] += c[from];
        c[from] = 0;
    }

    cup.a = c[0]; cup.b = c[1]; cup.c = c[2];
}

long long bfs() {
    queue<Cups> q;
    Cups starting;
    starting.a = values[0]; starting.b = 0; starting.c = 0; starting.steps = 0;
    q.push(starting);

    set<tuple<int, int, int> > seen;
    seen.insert({values[0], values[1], values[2]});

    while (!q.empty()) {
        Cups front = q.front();
        q.pop();

        if (front.a == values[0]/2 && front.b == values[0]/2 && front.c == 0 ||
            front.a == 0 && front.b == values[0]/2 && front.c == values[0]/2 ||
            front.a == values[0]/2 && front.b == 0 && front.c == values[0]/2) {
                return front.steps;
            }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                Cups aux = front;
                aux.steps++;
                pour(aux, i, j);
                q.push(aux);
            }
        }
    }
    return 0;
}


int main() {
    cin >> values[0] >> values[1] >> values[2];
    long long ans = bfs();
    if (!ans) cout << "NO" << "\n";
    else cout << ans << "\n";
}