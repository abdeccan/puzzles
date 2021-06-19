#include <iostream>
#include <vector>
#include <map>
using namespace std;


/*
We have an array of unsorted elements. However exactly one element is missing and another element is appearing twice. Find them both.

	3 4 2 1 6 4 --> input array
	
	1 2 1 1 1 


	3 4 2 1 6 5 --> original array

Approach 1: create a hash map for all the numbers as the key and the number of occurrences as the values. the key with occurrence (value) as 2 is the repeat and the key that is missing is the missing number.

Approach 2: 

*/

void findNums_Map(vector<int> inList) {
    	map<int, int> mymap;
	int tmp = 0;
	int repeat_num, missing_num;

	// step 1: insert values into map and get the repeat_num
	for(auto &v : inList) {
		if(mymap.find(v) != mymap.end()) {
			// number is present
			tmp = mymap[v];
			mymap[v] = ++tmp;
			repeat_num = v;
			tmp = 0;
		} else {
			mymap[v] = 1;
		}
	}
	// step 2: run through the map using the min element (this will be first elem in map sine its ordered map)
	map<int, int>::const_iterator it = mymap.begin();
	int k1 = it->first;
	for(unsigned int i = k1; i < inList.size(); i++) {
		if(mymap.find(i) == mymap.end()) {
			// this is missing num
			missing_num = i;
		} else if(mymap[i] > 1) {
            repeat_num = i;
        }
	}

	cout <<"Repeat num is " << repeat_num << endl;
	cout <<"Missing num is " << missing_num << endl;
}

void findNums_FreqArray(vector<int> inList) {
    if(inList.empty()) return;

    vector<int> freqArray(inList.size());

    for(int idx = 0; idx < inList.size();idx++) {
        freqArray[inList[idx]]++;        
    }

    int repeat_num, missing_num;
    for(int idx = 0; idx < freqArray.size();idx++) {
        if(freqArray[idx] > 1)
            repeat_num = idx;
        else if(freqArray[idx] == 0)
            missing_num = idx;
    }
    cout <<"Repeat num is " << repeat_num << endl;
	cout <<"Missing num is " << missing_num << endl;
}

int main() {
	vector<int> inList = {3, 3, 2, 1, 6, 4};

    findNums_FreqArray(inList);
}