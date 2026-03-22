#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int> > fence;
    int grid[1001][1001] = {0};
    int N;
    string s;
    cin >> N;
    cin >> s;
    pair<int, int> place;
    place.first = 0;
    place.second = 0;
    int left = INT_MAX, up = INT_MAX;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'N') {
            place.first += 1;
            fence.push_back(place);
            up = max(up, place.first);
        }
        else if (s[i] == 'S') {
            place.first -= 1;
            fence.push_back(place);
            up = max(up, place.first);
        }
        else if (s[i] == 'E') {
            place.second += 1;
            fence.push_back(place);
            left = min(left, place.second);
        }
        else if (s[i] == 'W') {
            place.second -= 1;
            fence.push_back(place);
            left = min(left, place.second);
        }
    }
    for (int i = 0; i < fence.size(); i++) {
        grid[fence[i].first+up][fence[i].second-left] = 1;

    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}