#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve_position_of_cow(ll c, ll t) {
    if (c == t) return c;
    ll p = c;
    ll cur_t = c;
    
    while (cur_t < t) {
        if (p == 0) {
            cur_t++;
            p = cur_t / 2;
        }

        else if (p > cur_t / 2) {

            ll next_unsafe_t = 2 * p;
            
            if (next_unsafe_t > t) {
                return p;
            }
            
            cur_t = next_unsafe_t;
            p--; 
        }
        
        else {

            ll dist_to_0 = p;
            ll remaining_time = t - cur_t;
            
            if (remaining_time < dist_to_0) {
                return p - remaining_time;
            }
            
            cur_t += dist_to_0;
            p = 0;
        }
    }
    return p;
}

ll solve_cow_at_position(ll x, ll t) {
    if (t == 0) return 0;
    
    while (t > 0) {
        if (x == t) return x; 
        
        if (x > t / 2) return x;
        if (x == t / 2) {
            x = 0;
            t--;
        }
        
        else {
            
            ll k = (t - 2 * x) / 3;
            if (k == 0) k = 1;
            x += k;
            t -= k;
        }
    }
    return x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    while (Q--) {
        ll type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            
            cout << solve_position_of_cow(a, b) << "\n";
        } else {
            cout << solve_cow_at_position(a, b) << "\n";
        }
    }
    return 0;
}