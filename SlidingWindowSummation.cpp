#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

void solve() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    string r;
    cin >> r;

    int target = r[0] - '0';

    ll total_min_ones = 0;
    ll total_max_ones = 0;
    int curr_max = 0;
    int curr_min = 0;
    int min_diff = 1e7;

    for (int i = 0; i < K; i++) {
        int count_0 = 0; // count if b[i] == 0
        int count_1 = 1; //count if b[i] == 1

        int current_val = 0; 

        int curr_index = i;
        
        while (curr_index + K < N) {
            int r_curr = r[curr_index] - '0';
            int r_next = r[curr_index + 1] - '0';
            int r_last = r[curr_index + K] - '0';
            
            current_val ^= (r_curr ^ r_next);
            
            if (current_val == 1) count_0++;
            else count_1++;
            
            curr_index += K;
        }
        
        //min ans
        if (count_0 < count_1) {
            total_min_ones += count_0;
            curr_min ^= 0;
        } 
        else {
            total_min_ones += count_1;
            curr_min ^=1;
        }
        
        //max ans
        if (count_0 > count_1){
            total_max_ones += count_0;
            curr_max ^= 0; 
        }
        
        else {
            total_max_ones += count_1;
            curr_max ^= 1;
        }
        int diff = abs(count_0 - count_1);
        if (diff < min_diff) min_diff = diff;
    }

    if (curr_min != target) {
        total_min_ones += min_diff;
    }


    if (curr_max != target) {
        total_max_ones -= min_diff;
    }


    cout << total_min_ones << " " << total_max_ones << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}