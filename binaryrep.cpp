#include <iostream>
#include <vector>
using namespace std;

void printBinaryNumsUntil(int N) {
    // logic: if N == 3, then we need to print 000, 001 ... 111
    // if N == 2, we need to print 00, 01, 10, 11
    // so we can continue to divide by 2 and print the reminder while
    // continuing to divide the quotient by 2
    //int n = pow(2, N) - 1;
    char ch[]  = {'0', '1'};
    vector<string> clist,plist;
    clist.push_back("0");
    clist.push_back("1");
    while(N-- > 1) {
        plist = clist;
        clist.clear();
        for(auto s:plist)
         clist.push_back(ch[0]+s);
          for(auto s:plist)
         clist.push_back(ch[1]+s);

    }

    for(auto s : clist) {
        cout << s << endl;
    }
    cout << endl;
}

int main() {
    cout << "Print the binary representation of numbers until 2^N" << endl;
    int N = 10;
    printBinaryNumsUntil(N);
    return 0;
}