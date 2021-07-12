#include <iostream>
#include <chrono>
using namespace std;

/* 
    logic: here the arr contains the sizes of matrix, index i = 0 and i = 1 give the dimensions
    of one matrix and so on till the end. we need to find the min cost of multiplying all the matrices
    together. which sequence of matrices we pick determines the overall cost.
    Cost of a matrix multiplication is actually the total number of all multiplications done.
*/
int solve_rec(int arr[], int i, int j) {
    int minCost = INT_MAX;

    // base condition: for matrix multiplication we need to have atleast two indices.
    // here i and j are the start and end points for the arr under consideration.
    // hence i should not be equal to j --> single elem array.
    // also i should not be greater than j --> zero size array.
    // so the condition we need to break is i >= j for the base condition.
    if (i >= j) return 0;

    // now the loop
    for(int k = i; k <= j - 1; k++) {
        // split the problem into 2 subproblems which will each return their cost
        // then compute the cost of these matrices
        int tmpCost = solve_rec(arr, i, k) + // sub problem # 1
                        solve_rec(arr, k + 1, j) +  // sub problem # 2
                            arr[i - 1] * arr[k] * arr[j];   // cost of above 2 sub problems

        if(tmpCost < minCost) minCost = tmpCost;
    }

    return minCost;
}

int memo[1001][1001];

int solve_memoized(int arr[], int i, int j) {
    int minCost = INT_MAX;

    // base condition: for matrix multiplication we need to have atleast two indices.
    // here i and j are the start and end points for the arr under consideration.
    // hence i should not be equal to j --> single elem array.
    // also i should not be greater than j --> zero size array.
    // so the condition we need to break is i >= j for the base condition.
    if (i >= j) return 0;

    // check memo table first
    if(memo[i][j] != -1) return memo[i][j];

    // now the loop
    for(int k = i; k <= j - 1; k++) {
        // split the problem into 2 subproblems which will each return their cost
        // then compute the cost of these matrices
        int tmpCost = solve_memoized(arr, i, k) + // sub problem # 1
                        solve_memoized(arr, k + 1, j) +  // sub problem # 2
                            arr[i - 1] * arr[k] * arr[j];   // cost of above 2 sub problems

        if(tmpCost < minCost) minCost = tmpCost;
    }

    memo[i][j] = minCost;

    return minCost;
}

int main() {
    cout << "Matrix chain multiplication base code" << endl;
    int arr[] = {40, 20, 30, 10, 30};
    auto t_start = std::chrono::high_resolution_clock::now();
    int minCost = solve_rec(arr, 1, sizeof(arr)/sizeof(int) - 1);
    auto t_end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    cout << "Min num of matrix multiplications (recursion) = " << minCost << " time elapsed " << elapsed_time_ms << endl;
    
    memset(memo, -1, sizeof(memo));
    t_start = std::chrono::high_resolution_clock::now();
    minCost = solve_memoized(arr, 1, sizeof(arr)/ sizeof(int) - 1);
    t_end = std::chrono::high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
    cout << "Min num of matrix multiplications (memoized) = " << minCost << " time elapsed " << elapsed_time_ms << endl;

    return 0;
}