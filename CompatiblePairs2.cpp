#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N;
    long long A, B;
    cin >> N >> A >> B;
    vector<pair<long long, long long>> cows(N);
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }

    unordered_map<long long, long long> id_count;
    for (const auto& cow : cows) {
        id_count[cow.second] = cow.first;
    }

    long long total_pairs = 0;

    for (auto& [d, count] : id_count) {
        if (count <= 0) continue; 

        long long d_prime_A = A - d;
        if (id_count.find(d_prime_A) != id_count.end() && id_count[d_prime_A] > 0 && d_prime_A != d) {
            long long pairs = min(count, id_count[d_prime_A]);
            total_pairs += pairs;
            id_count[d] -= pairs; 
            id_count[d_prime_A] -= pairs; 
        }

        long long d_prime_B = B - d;
        if (id_count.find(d_prime_B) != id_count.end() && id_count[d_prime_B] > 0 && d_prime_B != d) {
            long long pairs = min(count, id_count[d_prime_B]);
            total_pairs += pairs;
            id_count[d] -= pairs; 
            id_count[d_prime_B] -= pairs; //WEEE more tests
        }
    }

    for (auto& [d, count] : id_count) { //heheh
        if (count <= 0) continue; 

        if (2 * d == A || 2 * d == B) {
            long long pairs = count / 2; 
            total_pairs += pairs;
            id_count[d] -= pairs * 2; 
        }
    }

    cout << total_pairs << "\n";
    return 0;
}