#include <iostream>
using namespace std;

int getMaxProfit(int wt[], int val[], int N) {
    // this is a variation of the unbounded knapsack problem
    // this falls under unbounded because a piece of cut rod can be again cut into smaller pieces.
    // whereas in the classic 0-1 knapsack we are given a fixed collection of pieces (objects).

    // the bottom up table remains the same
    int capacity = N;
    int T[N + 1][capacity + 1];

    // initialization
    for(int i = 0; i < N + 1; i++) T[i][0] = 0;
    for(int j = 0; j < capacity + 1; j++) T[0][j] = 0;

    // choice diagram
    for(int i = 1; i < N + 1; i++) {
        for (int j = 1; j < capacity + 1; j++) {
            if(wt[i - 1] <= j) {
                T[i][j] = max(val[i - 1] + T[i][j - wt[i - 1]], T[i - 1][j]);
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[N][capacity];
}

int main() {
    cout << "Rod cutting for max profit" << endl;
    int length[] =   {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] =    {1, 5, 8, 9, 10, 17, 17, 20};

    int maxProfit = getMaxProfit(length, price, sizeof(length)/ sizeof(int));
    cout << "Max profit = " << maxProfit << endl;

    return 0;
}