#include <iostream>
#include <vector>
using namespace std;

int getMaxSubsequenceSum (vector<int> &inList) {
    int max_sum = 0;
    for (auto i : inList) {
        int tmp_max = 0;
        for (auto j : inList) {
            tmp_max += j;
            if(tmp_max < max_sum) {
                break;
            } else {
                max_sum = tmp_max;
                cout << "swapping max_sum " << max_sum << endl;
            }
        }
    }
    return max_sum;
}


int main () {
    int arr[] = {1, 2, 3 , -1, 7 , 8};
    vector<int> myInput;
    for(int idx = 0; idx < sizeof(arr); idx++) {
        myInput.push_back(arr[idx]);
    }
    cout << " Assigned input.." << endl;

    int max_sum = getMaxSubsequenceSum(myInput);
    cout << "Max sum is " << max_sum << endl;
    return 0;
}

