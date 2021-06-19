#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Given a sorted array as a vector, remove duplicate elements
    int removeDuplicatesFromSortedArray(vector<int>& nums) {
        vector<int>::iterator iter =  nums.begin();
        int tmp =  *iter;
        iter++;
        for(;iter != nums.end();++iter) {
            if(tmp == *iter) {
                iter = nums.erase(iter);    // if duplicate erase it
                if(iter == nums.end()) {
                    break;
                }
                // advance only if the next value is not the same as 'tmp'
                if(*iter != tmp) {
                    ++iter;
                }
            }
            tmp = *iter;
        }
        
        return nums.size();
    }

    void printArr(vector<int> arr) {
        for(int index = 0 ; index < arr.size(); index++)
            cout << "   " << arr[index] ;
    }
};

int main() {
    int arr[] = {0,1,1,1,2,2,3,3,4};
    vector<int> myVector (arr, arr+sizeof(arr)/ sizeof(int));

    Solution sol;
    cout << "Before sorting" << endl;
    sol.printArr(myVector);

    int size = sol.removeDuplicatesFromSortedArray(myVector);
    cout << endl;
    cout << "After sorting" << endl;
    sol.printArr(myVector);
    cout << endl;
}