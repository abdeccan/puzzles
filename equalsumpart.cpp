#include <iostream>
using namespace std;

bool getEqualSumPart(int arr[], int N) {
    
    int sum = 0;
    for(int i = 0; i < N; i++) sum += arr[i];
    if(sum % 2 != 0) return false;

    // Sum to find is sum/2. If yes, automatically the other part will be sum/2.

    // we need to have a table (top-down) of bools with size 'size' * 'sum/2'
    bool T[N + 1][sum/2 + 1];
    for (int j = 0; j < sum/2 + 1; j++) T[0][j] = false;
    for (int i = 0; i < N + 1; i++) T[i][0] = true;
    
    // convert the choice diagram
    // we start with index =1 here since the initialization covered the index = 0
    for(int i = 1; i < N + 1; i++) {
       for(int j = 1; j < sum/2 + 1; j++) {
              if(arr[i-1] <= j) {
               T[i][j] = (T[i - 1][j - arr[i - 1]]) || T[i-1][j];
           } else {
               T[i][j] = T[i - 1][j];
           }
       }
    }

    for(int i = 0; i < N + 1; i++) {
        cout << endl;
        for(int j = 0; j < sum/2 + 1; j++)
            cout <<"    " << T[i][j];
    }
    cout << endl;
    

    return T[N][sum/2];
}

int main() {
    cout << "Equal sum partition" << endl;

    int arr[] = {2, 4, 10, 1, 5};
    int N = sizeof(arr)/ sizeof(int);
    
    bool isEqualSumPart = getEqualSumPart(arr, N);
    cout <<  "isEqualSumPart = " << isEqualSumPart << endl;
    return 0;
}