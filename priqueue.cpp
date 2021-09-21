#include <iostream>
#include <queue>
using namespace std;

int main () {
    cout << "Print kth smallest and largest elements from array" << endl;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int K = 3;
    priority_queue<int> maxHeap;
    
    for(auto v : arr) {
        maxHeap.push(v);
        if(maxHeap.size() > K) maxHeap.pop();
    }
    cout << "Kth smallest is " << maxHeap.top() << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(auto v : arr) {
        minHeap.push(v);
        if(minHeap.size() > K) minHeap.pop();
    }

    cout << "Kth largest is " << minHeap.top() << endl;

    return 0;
}