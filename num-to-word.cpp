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
    const vector<string> one_to_twenty = {  "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    

    if(num == 0) return "zero";

    if(num > 0 && num < 10) return one_digits[num];

    if(num > 10 && num < 20) return two_digits[num - 1];

    if(num % 10 == 0 && num < 100) return tens[num - 1];

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
        num = num % (hdPart * HD);  // remaining = 23 out of xxx,123
        word.append(numToWord(hdPart)).append(" hundred ");
    }

    if(num <= 20) {
        // directly stick the string
        return one_to_twenty[num];
    }
    else if (num % 10 == 0) {
        return tens[num - 1];
    } else {
        int onePart = num % 10;
        int tenPart = num / 10;
        return tens[tenPart - 1] + one_to_twenty[onePart];
    }
}

int main () {
    cout << "Print the text form of a given number i.e. 123 should be printed as 'One hundred twenty three'" << endl;

    int num = 123;
    string s = numToWord(num);
    cout << "Word is " << s << endl;

    return 0;
}