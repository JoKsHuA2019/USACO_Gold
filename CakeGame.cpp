#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> cake;
    int T, N, b, e, n, sum = 0, ep = 0;
    bool done = false;
    cin >> T;
    for (int z = 0; z < T; z++) {
        done = false;
        cin >> N;
        sum = 0, b = 0, e = 0;
        for (int i = 0; i < N; i++) {
            cin >> n;
            sum += n;
            cake.push_back(n);
        }
        b = cake[N/2-1] + cake[N/2];
        cake.erase(cake.begin() + N/2-1);
        cake[N/2-1] = b;
        ep = N/2-1;
        while (!done) {
            // cout << b << " " << e << endl;
            // for (int element : cake) {
            //     cout << element << " ";
            // }
            //cout << endl;
            e += max(cake.front(), cake.back());
            if (cake.front() > cake.back()) {
                cake.pop_front();
                if (cake.size() == 2) {
                    b = cake.front() + cake.back();
                    done = true;
                    break;
                }
                b += cake[cake.size()/2+1];
                cake.erase(cake.begin() + cake.size()/2-1);
                cake[cake.size()/2-1] = b;
            }
            else {
                cake.pop_back();
                if (cake.size() == 2) {
                    b = cake.front() + cake.back();
                    done = true;
                    break;
                }
                b += cake[cake.size()/2-1];
                cake.erase(cake.begin() + cake.size()/2-1);
                cake[cake.size()/2-1] = b;
            }
        }
        cout << b << " " << e << endl;
        cake.clear();
    }
}