#include <iostream>
using namespace std;

int getSubsetsMatchingSum(int arr[], int N, int sum) {
    // create the top down matrix
    int T[N + 1][sum + 1];
    
    // initialize the table's first col & row
    // row: size of arr, col: sum
    for(int j = 0; j < sum + 1; j++) T[0][j] = 0;
    for(int i = 0; i < N + 1; i++) T[i][0] = 1;

    // choice diagram
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(arr[i-1] <= j) {
                // 0-1: include/ exclude
                T[i][j] = T[i-1][j - arr[i-1]] + T[i-1][j];
            } else {
                T[i][j] = T[i-1][j];
            }

        }
    }

    for(int i = 0; i < N + 1; i++) {
        cout << endl;
        for(int j = 0; j < sum + 1; j++)
            cout << T[i][j] << "    ";
    }

    return T[N][sum];
}

int main() {
    cout << "Count of number of subsets with the given sum" << endl;
    //int arr[] = {2, 3, 5, 6, 8, 10}; 
    int arr[] = {1, 5, 9, 4, 6};
    int sum = 10;
    int numSubsets = getSubsetsMatchingSum(arr, sizeof(arr)/ sizeof(int), sum);
    cout << "getSubsetsMatchingSum = " << numSubsets << endl;
    return 0;
}