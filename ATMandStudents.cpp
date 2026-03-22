#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N, S, a;
    vector<int> people;
    vector<long long> sum;
    long long sums = 0;
    cin >> T;
    for (int z = 0; z < T; z++) {
        cin >> N >> S;
        sums = 0;
        for (int i = 0; i < N; i++) {
            cin >> a;
            sums += a;
            people.push_back(a);
            sum.push_back(sums);
        }
        int i = 0, j = 0;
        int range = 0;
        int smalli = 0;
        int bigj = 0;
        while (i < N && j < N) {
            // if (people[i] < 0 && abs(people[i]) > S) {
            //     j++;
            //     i++;
            // }
            while (sum[j]-sum[i] > S || sum[j]-sum[i] < 0) {
                i++;
            }
            j++;
            if (range < j - i) {
                smalli = i;
                bigj = j;
            }
            range = j - i;
        }
        cout << smalli << " " << bigj << endl;
    }
}