#include <iostream>
#include <vector>
using namespace std;
/*
    
    -2, -3, 4, -1,-2, 1, 5,-3

*/
int getMaxSubarraySum(vector<int> arr) {
    if(arr.empty()) return 0;

    int sum = arr[0];
    int maxSum = sum;
    for(auto i : arr) {
        if(sum < 0) sum = 0;
        sum += arr[i];
        if(maxSum < sum) maxSum = sum;
    }

    return maxSum;
}

int main() {
    cout <<"Kadane algo to find the maximum sub-array sum" << endl;
    vector<int> arr = /*{-2, 3, 4, -1,-2, 1, 5,-3};*/ {-2, 0, 2, -1,0, 1, 0,-1};
    
    int maxSum = getMaxSubarraySum(arr);
    cout << "Max sum " << maxSum << endl;
    return 0;
}