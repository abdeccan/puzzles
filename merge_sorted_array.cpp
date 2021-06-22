#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
	Merge two sorted arrays with O(1) extra space

	Two arrays of sizes m and n are both sorted individually. We need to take
	all the elements, sort them and put them back into the arrays.

	1	5 	9 	10 	15 	20

	2 	3 	8 	13
*/

void sort_BruteForce(vector<int> &a1, vector<int> &a2) {
	if(a1.empty() || a2.empty()) return;

	size_t s1 = a1.size();
	size_t s2 = a2.size();
	vector<int> a3(s1+s2);
	
	for(int i = 0, j = 0, k = 0; k < s1 + s2; k++) {
		if(k < s1) a3[k] = a1[i++];
		else a3[k] = a2[j++];
	}
	
	cout << "before sorting " << endl;
	for(int i = 0; i < s1 + s2; i ++) cout << "	" << a3[i];
	
	auto comp = [](int a, int b) {return a < b;};
	sort(a3.begin(), a3.end(), comp);
	cout << endl << "after sorting " << endl;
	// its sorted, now put it back
	for(int i = 0; i < s1; i++) a1[i] = a3[i];
	for(int i = 0; i < s2; i++) a2[i] = a3[s1 + i];
	for(int i = 0; i < s1; i ++) cout << "	" << a1[i];
	cout << endl;
	for(int i = 0; i < s2; i ++) cout << "	" << a2[i];
	cout << endl;
}

void sort_Better(vector<int> &a1, vector<int> &a2) {
	if(a1.empty() || a2.empty()) return;

	size_t s1 = a1.size();
	size_t s2 = a2.size();

	/*	
		1	5 	9 	10 	15 	20

		2 	3 	8 	13
	*/
	cout << endl << "before sorting" << endl;
	for(int idx = 0; idx < s1; idx++) cout << "	" << a1[idx];
	cout << endl;
	for(int idx = 0; idx < s2; idx++) cout << "	" << a2[idx];
	size_t s = std::max(s1, s2);
	auto swap = [](int& a, int& b) {
		int tmp = a; a = b; b = tmp;
	};
	for(int i = 0, j = 0, k = 0; k < s; k++) {
		if(a1[i] > a2[j]) {
			swap(a1[i], a2[j]);
			//j++;
			i++;
			sort(a2.begin(), a2.end());
		} else if(a1[i] < a2[j]) {
			i++;
		}
/*		cout << endl << "---------"<< endl;
		for(int idx = 0; idx < s1; idx++) cout << "	" << a1[idx];
		cout << endl;
		for(int idx = 0; idx < s2; idx++) cout << "	" << a2[idx];
*/
		
	}
	cout << endl << "after sorting" << endl;
	for(int idx = 0; idx < s1; idx++) cout << "	" << a1[idx];
	cout << endl;
	for(int idx = 0; idx < s2; idx++) cout << "	" << a2[idx];
	cout << endl;
}
inline int getElemAtGap(int idx, size_t gap, size_t s1, size_t s2) {
	if(idx + gap > s1) {
		return a2[idx + gap - s1];
	}
}

void sort_Optimal(vector<int> &a1, vector<int> &a2) {

	if(a1.empty() || a2.empty()) return;

	/*
		Here we are going to apply the GAP method (shell sort??) wherein we 
		keep on taking the GAP length and reduce it in half and move the window
		accordingly.
	*/

	size_t s = a1.size() + a2.size(); // s/2 will be first gap size

	/*	
		1	5 	9 	10 	15 	20

		2 	3 	8 	13

		1	5 	9 	10 	15 	20	2 	3 	8 	13
	*/

	for(int i = 0; i < s; i++) {
		
	}

}

int main () {
	vector<int> a1 = {1,	5, 	9, 	10, 	15, 	20};
	vector<int> a2 = {2, 	3, 	8, 	13};
	sort_Better(a1, a2);
	return 0;
}