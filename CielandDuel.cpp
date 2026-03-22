#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    multimap<int, string> cards;
    multiset<int, less<int> > we;
    int n, m;
    int e;
    string pos;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> pos;
        cin >> e;
        cards[e] = pos;
    }
    for (int i = 0; i < m; i++) {
        cin >> e;
        we.insert(e);
    }
    int i = 0, j = 0;
    while (i < j) {
        
    }
    for (auto it = cards.begin(); it != cards.end(); it++) {
        for (auto jt = we.begin(); jt != we.end(); jt++) 
    }
}