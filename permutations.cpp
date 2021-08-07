#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &input, vector<vector<int>> &output, vector<int> &permutation, vector<bool> &seen) {
    // base condition
    if(permutation.size() == input.size()){
        output.push_back(permutation);
        return;
    }

    // do the recursion
    for(int i = 0; i < input.size(); i++) {
        // logic: make choice
        // backtrack
        // undo choice

        if(!seen[i]) {

            seen[i] = true; // logic: make choice
            permutation.push_back(input[i]);
            
            backtrack(input, output, permutation, seen); // backtrack

            seen[i] = false;    // undo choice
            permutation.pop_back();
        }
    }
}

vector<vector<int>> computePermutations(vector<int> &input) {
    vector<vector<int>> output;
    vector<int> permutation;
    vector<bool> seen(input.size(), false);
    backtrack(input, output, permutation, seen);
    return output;
}

int main() {
    cout <<"Permutations of numbers" << endl;

    vector<int> input = {1,2,3,1};
    vector<vector<int>> output = computePermutations(input);

    for(auto v : output) {
        cout << endl;
        for(auto i : v) {
            cout << i << "  ";
        }
    }
    cout << endl;
    return 0;
}