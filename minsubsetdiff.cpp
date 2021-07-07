#include <iostream>
#include <vector>
using namespace std;

int getMinDiff(int arr[], int N) {
    // Logic: we are going to split this array into two sub arrays. The original array has a sum 'S'
    // and the sub arrays have the sums 'S1' and 'S2'. One of them is obviously less than S/2.
    // For simplicity sake, lets consider S1 < S/2 and S2 > S/2.
    // We know that S1 + S2 = S. We need to minimize the S2 - S1 value.
    // Since S2 = S - S1, we need to minimize (S - S1) - S1 = [S - 2S1]
    // For this we can make use of the subset sum problem approach and then find all possible values of
    // sums from the last row of the top-down table we build. From these values we can find the minimal 
    // value of [S - 2S1]

    int sum = 0;
    for(int i = 0; i < N; i++) sum += arr[i];

    // initialization: first row will all be '0' except first col. All row's first col are '1'.
    bool T[N + 1][sum + 1];
    for(int j = 0; j < sum + 1; j++) T[0][j] = false;
    for(int i = 0; i < N + 1; i++) T[i][0] = true;

    // choice diagram code
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if(arr[i - 1] <= j) {
                T[i][j] = T[i-1][j - arr[i-1]] || T[i-1][j];
            } else {
                T[i][j] = T[i-1][j];
            }
        }
    }

    for(int i = 0; i < N + 1; i++) {
        cout << endl;
        for(int j = 0; j < sum + 1; j++)
        cout << T[i][j] << "    " ;
    }


    // now we have the possible values for sums in the last row of the T
    // insert the last row into a vector
    vector<int> lastRow;
    for(int j = 0; j <= sum/2; j++) {
        if(T[N][j]) lastRow.push_back(j);
    }

    cout << endl;
    cout << "lastRow; ";
    for(auto v : lastRow) cout << v << "    ";

    int min = INT_MAX;
    for(auto v : lastRow) {
        if(min > sum - 2*v) min = sum - 2*v;
    }

    return min;
}

int main() {
    cout << "Minimum subset sum difference" << endl;
    //int arr[] = {1, 2 ,7};//{1, 6, 11, 5}; // {1, 2 ,7};
    int arr[] = {3, 1, 4, 2, 2, 1};
    int N = sizeof(arr)/ sizeof(int);
    int minDiff = getMinDiff(arr, N);
    cout << "min diff = " << minDiff << endl;
    return 0;
}