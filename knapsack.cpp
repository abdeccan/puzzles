#include <iostream>
#include <map>
#include <vector>
using namespace std;

int getMaxProfit_rec(int weights[], int values[], int N, int capacity) {
    // this is the classic recursive approach and is the fundamental to the 
    // other approaches like memo and top-down discussed below.
    // here we need to identify how to break down the problem into base condition
    // and then the choice diagram i.e. the different paths we could take. The paths
    // in this case are 0-1 i.e. pick and item or dont pick it.
    
    // base condition
    if(N == 0 || capacity == 0) return 0;

    // choices
    if(weights[N-1] <= capacity) {
        // 0 or 1
        return max(values[N-1] + getMaxProfit_rec(weights, values, N-1, capacity - weights[N-1]), 
                    getMaxProfit_rec(weights, values, N-1, capacity));
    } else {
        return getMaxProfit_rec(weights, values, N-1, capacity);
    }
}

int getMaxProfit_Memoize(int weights[], int values[], int N, int capacity) {

    // here we will store the computed values of the getMaxProfit_rec function in a table
    // and look it up where possible, thereby avoiding duplicate computations.
    // we would still be making recursive calls but the complexity is much lesser now.

    // the memo table where we will store values. the 2D table will contain the 2 variables as
    // rows and columns. Looking at the recursive implementation, we find that the params 'N'
    // and the 'capacity' are changing frequently. hence these will form the rows and columns 
    // for our 2D memo table. Also we will need the upper bounds for these 2 variables. Assuming
    // 100 and 100 as the upper bounds i.e. N <= 100, capacity <= 100. 
    // Initialize the table with a unique and unused value like -1.
    //
    static int T[101][101];  // static so that it gets init'd once
    memset(T, -1, sizeof(T));

    // base condition
    if(N == 0 || capacity == 0) return 0;

    // after checking base condition, check if the value is present in memo
    if(T[N][capacity] != -1) return T[N][capacity];

    // choices
    if(weights[N-1] <= capacity) {
        // 0 or 1
        T[N][capacity] = max(values[N-1] + getMaxProfit_Memoize(weights, values, N-1, capacity - weights[N-1]), 
                    getMaxProfit_Memoize(weights, values, N-1, capacity));
        return T[N][capacity];
    } else {
        T[N][capacity] = getMaxProfit_Memoize(weights, values, N-1, capacity);
        return T[N][capacity];
    }
}

int getMaxProfit_TopDown(int weights[], int values[], int N, int W) {
    // here we will create a table 'T' of size [N + 1] * [W + 1] and fill it up
    // with answers to smaller, sub problems
    // the final answer to our question would then be available at T[N][W]
    // the element at a particular index m,n is the solution of the DP problem until 
    // that point. Hence the answer to the original DP problem could be found at 
    // Table[N][W]

    int T[N+1][W+1];

    // initialize with the base condition values!
    for(int i = 0; i < N + 1; i++) T[i][0] = 0;
    for(int j = 0; j < W + 1; j++) T[0][j] = 0;    // this is the same as base condition we wrote in recursive soln

    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            if(weights[i-1] <= j) {
                int a = values[i-1] + T[i-1][j - weights[i-1]];
                int b = T[i-1][j];
                if(a > b) cout << " i = " << i << endl;
                
                T[i][j] = max(a, b);
            } else {
                T[i][j] = T[i-1][j];
            }
        }
    }

    for(int i = 0; i < N + 1; i++) {
        cout << endl;
        for(int j = 0; j < W + 1; j++)
            cout <<"    " << T[i][j];
    }
    cout << endl;

     // int curProf = T[N][W];
     int curWt= W;
     int row = N;
    // Display the chosen objects
    while ( curWt > 0 && row > 0)
    {
            if (T[row][curWt] > T[row-1][curWt])
            {
                    cout <<"  Item chosen   " <<  row;
                    curWt -= weights[row-1];
                    // curProf -= values[row];                    
            }
          row --;
        
    }
     cout << endl;

          return   T[N][W];
}

int main() {
    cout << "knapsack problem" << endl;
    int weights[] = {1, 6, 4,1, 2,3,6,1, 1};   //{10, 20, 30};
    int values[] = {4, 2, 1,2, 2,1,2,1 ,1};    //{60, 100, 120};
    int capacity = 7; //50;
    int size = 9;
    int maxProfit = getMaxProfit_rec(weights, values, size, capacity);
    cout << "Max profit by getMaxProfit_rec = " << maxProfit << endl;
    maxProfit = getMaxProfit_Memoize(weights, values, size, capacity);
    cout << "Max profit by getMaxProfit_Memoize = " << maxProfit << endl;
    maxProfit = getMaxProfit_TopDown(weights, values, size, capacity);
    cout << "Max profit by getMaxProfit_TopDown = " << maxProfit << endl;
    
    return 0;
}