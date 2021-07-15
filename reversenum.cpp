#include <iostream>
#include <deque>
#include <string>
using namespace std;

unsigned int getRevNum1(unsigned int num) {
    if (num == 0) return 0;

    // using deque
    deque<unsigned int> dq;
    while(num/10 > 0) {
        int tmp = num % 10;
        dq.push_front(tmp);
        num = num/10;
    }

    if(num > 0) dq.push_front(num);

    int revNum = 0; 
    while(!dq.empty()) {
        int size = dq.size();
        revNum += dq.back() * pow(10, size - 1);
        dq.pop_back();
    }

    return revNum;
}

unsigned int getRevNum2(unsigned int num) {
    if(num == 0) return 0;

    // format to string and reverse the string and back
    string s = to_string(num);
    reverse(s.begin(), s.end());

    unsigned int revNum = atol(s.c_str());
    return revNum;    
}

int main () {
    unsigned int num = 12340;
    unsigned int revNum1 = getRevNum1(num);
    cout << "Rev num = " << revNum1 << endl;

    unsigned int revNum2 = getRevNum2(num);
    cout << "Rev num = " << revNum2 << endl;

    return 0;
}