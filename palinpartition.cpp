#include <iostream>
using namespace std;

bool isPalindrome(string s, int i, int j) {
    string s1 = s.substr(i, j);
    string s2 = s1; 
    reverse(s2.begin(), s2.end());
    return s1 == s2;
}

int getPartitions(string s, int i, int j) {
    // logic: this comes under matrix chain multiplication pattern since we need to partition 
    // the given array to find optimal (min/ max) values.

    // base condition: for i == j, there is only one char. since 1 char string is already a Palindrome we dont need any
    // partition. similarly, if i > j, string is empty which again needs no partition
    if(i >= j) return 0;

    // one more special case to consider as base - if the string being passed is already a Palindrome we dont need
    // any more partition
    if (isPalindrome(s, i, j)) return 0;

    int mn = INT_MAX;
    for(int k = i; k < j - 1; k++) {
        int tmp = getPartitions(s, i, k) + getPartitions(s, k + 1, j) + 1;
        mn = min(mn, tmp);
    }

    return mn;
}

int main() {
    cout << "Palindrome partitioning" << endl;

    string s1 = "nitin";
    cout << isPalindrome(s1, 0, s1.size()) << endl;
    string s = "ababbbabbababa";
    int numPartitions = getPartitions(s, 0, s.size() - 1);
    cout << "Num partitions = " << numPartitions << endl;
    return 0;
}