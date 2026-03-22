#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

vector<long long> cows;
vector<pair<int, int> > stores;
vector<int> neighbors;

long long N, M, R, n, e;

long long sell(int gallons) {
    int g = gallons;
    long long sum = 0;
    int counter = 0;
    while (g > 0) {
        sum += min(stores[counter].second, g) * stores[counter].first;
        //cout << "gallons: " << g << ", money: " << stores[counter].first << endl;
        g -= min(stores[counter].second, g);
        counter++;
    }
    //cout << "sell: " << sum << endl;
    return sum;
}

long long rent(int cows) {
    long long sum = 0;
    for (int i = 0; i < cows; i++) {
        sum += neighbors[i];
    }
    //cout << "rent: " << sum << endl;
    return sum;
}

long long solve() {
    long long ans = 0;
    sort(cows.begin(), cows.end());
    sort(neighbors.begin(), neighbors.end());
    sort(stores.begin(), stores.end());
    reverse(stores.begin(), stores.end());
    reverse(cows.begin(), cows.end());
    reverse(neighbors.begin(), neighbors.end());
    // for (int i = 0; i < cows.size(); i++) {
    //     cout << cows[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i < cows.size(); i++) {
        cows[i] += cows[i-1];
    }
    for (int i = 0; i < cows.size(); i++) {
        ans = max(ans, sell(cows[i]) + rent(N-(i+1)));
    }
    return ans;
}

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        cin >> n;
        cows.push_back(n);
    }
    for (int i = 0; i < M; i++) {
        cin >> n >> e;
        stores.push_back(make_pair(e, n));
    }
    for (int i = 0; i < R; i++) {
        cin >> n;
        neighbors.push_back(n);
    }
    cout << solve() << endl;
    return 0;
}