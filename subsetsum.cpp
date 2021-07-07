#include <iostream>
#include <map>
#include <vector>
using namespace std;

    // here we will create a table 'T' of size [N + 1] * [W + 1] and fill it up
    // with answers to smaller, sub problems
    // the final answer to our question would then be available at T[N][W]
    // the element at a particular index m,n is the solution of the DP problem until 
    // that point. Hence the answer to the original DP problem could be found at 
    // Table[N][W]
bool subsetSum_TopDown(int arraySet[], int N, int sum) {
    
    bool T[N+1][sum+1];

    // initialize with the base condition values!
    for(int i = 0; i <= N; i++) T[i][0] = true;
    for(int j = 1; j <= sum; j++) T[0][j] = false;    // this is the same as base condition we wrote in recursive soln

    // convert the choice diagram
    // we start with index =1 here since the initialization covered the index = 0
    for(int i = 1; i < N + 1; i++) 
    {
        for(int j = 1; j <= sum; j++) 
        {
            if(arraySet[i-1] <= j) 
            {
                T[i][j] =  (T[i-1][j - arraySet[i-1]]) || T[i-1][j] ;
            } else 
                T[i][j] = T[i-1][j];
    
        }
    }

    for(int i = 0; i < N + 1; i++) {
        cout << endl;
        for(int j = 0; j < sum + 1; j++)
        cout << T[i][j] << "    " ;
    }

    int row = N;
    int col = sum;
    while(row > 0 && col > 0) {
        if(T[row][col] != T[row-1][col]){
            cout << "   Item chosen: " << row;
            col -= arraySet[row-1];
        }
        row--;
    }

    return T[N][sum];

}


int main() {
    cout << "Subset Sum problem" << endl;
    int InputSet[] = {1,3,1,1,6,7,9,2,3};
    int sum = 10;
    int size = 9;
    bool exists = subsetSum_TopDown (InputSet, size, sum);
    cout << " Subset Sum problem = " << exists << endl;
    
    return 0;
}