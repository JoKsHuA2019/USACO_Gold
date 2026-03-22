#include <iostream>
using namespace std;

void func(int disc, int from_pole, int to_pole, int aux_pole, int& tot) {
  if (disc == 0) return;
  func(disc-1, from_pole, aux_pole, to_pole, tot);
  tot++;
  func(disc-1, aux_pole, to_pole, from_pole, tot);
}

int main() {
  int N;
  cin >> N;
  int total = 0;
  func(N, 1, 3, 2, total);
  cout << total;
}
