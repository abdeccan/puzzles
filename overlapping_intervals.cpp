#include <iostream>
#include <vector>
using namespace std;

void printOverlappingIntervals(vector<vector<int>> pairs) {
    vector<vector<int>> out;
    auto cmp = [](vector<int> a, vector<int> b) {
        if(a[0] < b[0]) return true;
        else if (a[0] == b[0] && a[1] < b[1]) return true;
        return false;
    };
    // step 1: sort the pairs (optional and needed if input is not sorted already)
    //cout << "before sorting pairs" << endl;
   // for(auto p : pairs) cout << p[0] << ", " << p[1] << endl;    
    sort(pairs.begin(), pairs.end(), cmp);
    //cout << "after sorting pairs" << endl;
    //for(auto p : pairs) cout << p[0] << ", " << p[1] << endl;

    /*
        {{1, 3}, {2, 6}, {8, 10}, {8, 8}, {9, 11}, {15, 18}, {2, 4}, {16, 17}}
    */
    
    // step 2: run through pairs and check if they can be merged
    vector<int> currPair = pairs[0];
    for(int idx = 0; idx < pairs.size()-1; idx++) {
        if(currPair[1] < pairs[idx+1][0]) {
            // this means there is a break in interval
            vector<int> tmp;
            tmp.push_back(currPair[0]);
            tmp.push_back(currPair[1]);
            out.push_back(tmp);            
            cout << "Break in interval after " << currPair[0] << ", " << currPair[1] << endl;
            currPair = pairs[idx+1];
        }
        else {
            vector<int> tmp;
            tmp.push_back(currPair[0]);
            tmp.push_back(std::max(pairs[idx+1][1], currPair[1]));
            //out.push_back(tmp);
            currPair = tmp;
            cout << "Merged, curr pair now is " << currPair[0] << ", " << currPair[1] << endl;
        }
    }
    out.push_back(currPair);

    // step 3: print the output pairs
    cout << "after merging pairs" << endl;
    for(auto p : out) cout << p[0] << ", " << p[1] << endl;
}

int main() {
    cout << "Print all the overlapping intervals from the input collection" << endl;

    vector<vector<int>> pairs;
    pairs.push_back(vector<int>({1, 3}));
    pairs.push_back(vector<int>({2, 6}));
    pairs.push_back(vector<int>({8, 10}));
    pairs.push_back(vector<int>({8, 8}));
    pairs.push_back(vector<int>({9, 11}));
    pairs.push_back(vector<int>({15, 18}));
    pairs.push_back(vector<int>({2, 4}));
    pairs.push_back(vector<int>({16, 17}));

    printOverlappingIntervals(pairs);

    return 0;
}