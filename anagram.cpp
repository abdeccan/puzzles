#include <iostream>
#include <vector>
using namespace std;

bool backTrack(string s, vector<string> &anagrams, string &anagram, vector<bool> &seen) {
    // base condition
    if(anagram.size() == s.size()) {

        anagrams.push_back(anagram);
        return true;
    }

    // logic

    // use recursion
    for(int i = 0; i < s.size(); i++) {
        if(seen[i]) continue;

        // make choice
        anagram.push_back(s[i]);
        seen[i] = true;

        // backtrack further
        backTrack(s, anagrams, anagram, seen);
        
        // undo choice
        seen[i] = false;
        anagram.pop_back();
    }

    return false;
}

void printAnagrams(string s) {
    // backtrack the solution 
    int size = s.size();
    vector<bool> seen(size, false);
    string anagram;
    vector<string> anagrams;
    backTrack(s, anagrams, anagram, seen);
    for(string a : anagrams)
        cout << a << endl;
}

int main() {
    cout << "Print anagrams" << endl;
    string s = "ate";
    printAnagrams(s);
    return 0;
}
