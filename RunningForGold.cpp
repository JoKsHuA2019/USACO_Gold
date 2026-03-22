#include <iostream>
using namespace std;

int main() {
    int T, N, n;
    cin >> T;
    int arr[50001][5];
    for (int z = 0; z < T; z++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < 5; j++) {
                if (arr[i][j] > arr[i+1][j])
            }
        }


    }
}