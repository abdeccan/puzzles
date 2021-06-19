#include <iostream>
#include <vector>
using namespace std;

inline void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void sortList(vector<int> &inList) {
	/*
		the idea here is to keep three pointers: 
		everything to left of low = 0 i.e. 0...low-1
		everything to the right of high = 2 i.e. high+1 ...N
		everything in between = 1
		three pointers low, mid and high
	*/
	unsigned int low = 0, mid = 0, high = inList.size() -1;
	for(unsigned int idx = 0; idx < inList.size(); idx++) {
		if(inList[mid] == 0) {
			swap(inList[mid], inList[low]);
			low++;
			mid++;
		} else if(inList[mid] == 2) {
			swap(inList[mid], inList[high]);
			--high;
		} else if(inList[mid] == 1) {
			mid++;
		}
	}
}

int main() {
	vector<int> inList = {0,1,1,2,1,2,0,2,1};
	cout << "Before sorting" << endl;
	for(auto &v : inList) {
		cout  << v << " ";
	} 
	sortList(inList);
    cout << endl;
	cout << "After sorting" << endl;
	for(auto &v : inList) {
		cout  << v << " ";
	}
    cout << endl;
}