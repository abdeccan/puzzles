#include <iostream>
using namespace std;

int numOcc = 0;

int getLastIndex(int arr[], int s, int val) {
    int start = 0;
    int end = s - 1;
    int mid = start + (end - start)/2;  // better way of writing (start + end)/2 
    int lastIndex = -1;
    
    while(start <= end) {
        mid = start + (end - start)/2;
        if(arr[mid] == val) {
            lastIndex = mid;
            start = mid + 1;
            cout << "found 10 at " << lastIndex << " num occ = " << numOcc << endl; 
            ++numOcc;
        }         
        else if(arr[mid] < val) {
            // we need to search to the right
            start = mid + 1;
        } else {
            // we need to search to the left
            end = mid - 1;
        }
    }

    return lastIndex;
}

int getNumOccurrences(int arr[], int size, int val) {
    int start = 0;
    int end = size - 1;
    int mid = 0;

    int cnt = 0;

    while(start <= end) {
        mid = start + (end - start)/2;
        if(arr[mid] == val) cnt++;
        while()
    }
}

int main() {
    cout << "Find last occurrence of an element in a sorted array" << endl;
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int val = 10;
    size_t s = sizeof(arr)/sizeof(int);
    int lastIndex = getLastIndex(arr, s, val);
    cout << "Last index = " << lastIndex << endl;

    cout << "numOcc = " << numOcc << endl;
    //assert(lastIndex == 4); // test code!
    return 0;
}