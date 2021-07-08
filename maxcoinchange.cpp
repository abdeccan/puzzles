#include <iostream>
using namespace std;

int getMaxChange(int coins[], int N, int capacity) {
    // logic: same as count of subset sum problem, just that this is unbounded knapsack problem
    // initialize the base
    int T[N + 1][capacity + 1];
    for(int j = 0; j < capacity + 1; j++) T[0][j] = 0;
    for(int i = 0; i < N + 1; i++) T[i][0] = 1;

    // choice diagram
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < capacity + 1; j++) {
            if(coins[i - 1] <= j) {
                // unbounded and hence consider current item also. and sum them up
                T[i][j] = T[i][j - coins[i - 1]] + T[i - 1][j];
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[N][capacity];
}

int main() {
    cout << "Maximum coin change problem" << endl;
    int coins[] = {1, 2, 3};
    int N = 4;

    int maxChange = getMaxChange(coins, sizeof(coins)/sizeof(int), N);
    cout << "max change = " << maxChange << endl;
    return 0;
}