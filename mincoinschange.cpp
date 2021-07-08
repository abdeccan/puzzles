#include <iostream>
using namespace std;

int getMinCoins(int coins[], int N, int W) {
    // logic: here the initialization is bit tricky in that, we fill the first row
    // which is the sum, with INT_MAX - 1 since we are asking for minimum number of coins
    // from an empty array collection to meet a certain sum.
    // First column of other rows are still '0'.
    // Second thing to note here is that the second row needs to be specially handled as
    // well. Please note second row means, we have row = 1 i.e. first element is included.
    // With this first coin alone, would we be able to meet the sum at that point i.e. index 'j'
    // Wherever j % coins[i - 1] == 0, fill out j/ coins[i - 1]; else fill out INT_MAX - 1.

    int T[N + 1][W + 1];
    
    // Init: first row and col
    for(int i = 0; i < N + 1; i++) T[i][0] = 0;
    for(int j = 0; j < W + 1; j++) T[0][j] = INT_MAX - 1;

    // Init: special case handling for the second row
    for(int j = 1; j < W + 1; j++) {
        T[1][j] = j % coins[0] == 0 ? j / coins[0] : INT_MAX - 1;
    }

    for(int i = 2; i < N + 1; i++) {    // i = 0 and 1 handled above
        for(int j = 1; j < W + 1; j++) {
            if(coins[i - 1] <= j) {
                T[i][j] = min(1 + T[i][j - coins[i - 1]], T[i - 1][j]); // we are adding '1' to indicate we picked that coin
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[N][W];
}

int main() {
    cout << "Minimum number of coins required to fulfil a sum" << endl;
    int coins[] = {1, 2, 5, 3};
    int val = 5;
    int minCoins  = getMinCoins(coins, sizeof(coins)/ sizeof(int), val);
    cout << "Min coins req = " << minCoins << endl;
    return 0;
}
