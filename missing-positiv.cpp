#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int getMissing(vector<int> a) {
    unordered_set<int> numset;
    for(auto &i : a)
        numset.insert(i);

    int cnt = 1;
    for(; cnt < (int)numset.size(); cnt++) {
        if(numset.find(cnt) == numset.end())
            break;
    }
    if(cnt == numset.size()) cnt++;
    return cnt;
}

int main() {
    vector<int> a = {1, 3, 6, 4, 1, 2};//{1, 2 ,3};
    int missing = getMissing(a);
    cout << "First missing positive number from array: " << missing << endl;
    return 0;
}