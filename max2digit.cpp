#include <iostream>
#include <vector>
using namespace std;

int getMaxNum(string s) {
    int maxNum = 0;
    char num[2];

    for(int i = 0; i < s.size() - 1; i++) {
        num[0] = s[i];
        num[1] = s[i+1];
        int tmpMax = atol(num);
        maxNum = max(maxNum, tmpMax);
    }

    return maxNum;
}

int main() {
    // given a string containing only numbers, print the maximum 2 digit number 
    // that appears contiguously in the given string
    // e.g. 50552 --> two digit numbers = 50, 05, 55, 52 --> max = 55

    string num = "50552";

    int maxNum = getMaxNum(num);

    cout << "Max num = " << maxNum << endl;
    return 0;
}
