#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    long long A, B, count5, id5;
    cin >> N >> A >> B;
    vector<long long> cows2(N);
    unordered_map<long long, long long> cowCount;
    for (int i = 0; i < N; i++) {
        cin >> count5 >> id5;
        cowCount[id5] = count5;
        cows2[i] = id5;
    }

    sort(cows2.begin(), cows2.end());

    long long totalPairs = 0;
    
    for (const auto& entry : cowCount) {
        long long id = entry.first;
        long long count = entry.second;

        if (count <= 0) continue;

        long long a = A-id;
        long long b = B-id;

        if (binary_search(cows2.begin(), cows2.end(), a) && cowCount[a] > 0) {
            if (a == id) {
                long long pair = count / 2;
                totalPairs += pair;
                cowCount[id] -= pair * 2;
            }
            else {
                long long pair = min(cowCount[a], count);
                totalPairs += pair;
        
                cowCount[id] -= pair;
                cowCount[a] -= pair;
            }
        }

        if (binary_search(cows2.begin(), cows2.end(), b) && cowCount[b] > 0) {
            if (b == id) {
                long long pair = count / 2;
                totalPairs += pair;
    
                cowCount[id] -= pair * 2;
            }
            else {
                long long pair = min(cowCount[b], count);
                totalPairs += pair;

                cowCount[id] -= pair;
                cowCount[b] -= pair;
            }
            
        }
    }

    cout << totalPairs << "\n";

    return 0;
}
