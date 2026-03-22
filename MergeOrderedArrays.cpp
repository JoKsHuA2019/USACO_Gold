#include <iostream>
#include <vector>
using namespace std;

vector<long long> v1,v2,ans;

int main() {
  long long x;
  while (true) {
    cin >> x;
    if (x != -1) v1.push_back(x);
    else break;
  }
  while (true) {
    cin >> x;
    if (x != -1) v2.push_back(x);
    else break;
  }
  int l = 0, r = 0;
  while (l < v1.size() && r < v2.size()) {
    if (v1[l] >= v2[r]) {
      ans.push_back(v1[l]);
      l++;
    }
    else {
      ans.push_back(v2[r]); 
      r++;
    }
  }
  for (int i = l; i < v1.size(); i++) ans.push_back(v1[i]);
  for (int i = r; i < v2.size(); i++) ans.push_back(v2[i]);

  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}