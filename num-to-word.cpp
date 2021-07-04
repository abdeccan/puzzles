#include <iostream>
#include <vector>
#include <map>
using namespace std;

string numToWord(int num) {
    // sanity checks here!

    string word;
    const int BN = 1000000000;
    const int MN = 1000000;
    const int TH = 1000;
    const int HD = 100;
    const int TEN = 10;
    const vector<string> one_digits = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const vector<string> two_digits = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const vector<string> tens = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "one hundred"};
    
    int tmp = num;

    int bnPart = num / BN; 
    if(bnPart > 0) { 
        num = num % (bnPart * BN);    // remaining
        word.append(numToWord(bnPart)).append(" billion ");
    }

    int mnPart = num/ MN;
    if(mnPart > 0) {
        num = num % (mnPart * MN);    // remaining
        word.append(numToWord(mnPart)).append(" million ");
    }

    int thPart = num / TH;
    if(thPart > 0) {
        num = num % (thPart * TH);    // remaining
        word.append(numToWord(thPart)).append(" thousand ");
    }

    int hdPart = num / HD;
    if(hdPart > 0) {
        num = num % (hdPart * HD);  // remaining
        word.append(numToWord(hdPart)).append(" hundred ");
    }

    int oneplace = num % 10;
    if(oneplace > 0) {
        num -= oneplace;
        word.append(tens[num/10 - 1]).append(one_digits[oneplace]);
    } else{
        word.append(tens[num/10 - 1]);
    }
    
    
    //word.append(numToWord(num));

   //printf("Word is %s\n", word.c_str());

    return word;
}

int main () {
    cout << "Print the text form of a given number i.e. 123 should be printed as 'One hundred twenty three'" << endl;

    int num = 100123;
    string s = numToWord(num);
    cout << "Word is " << s << endl;

    return 0;
}