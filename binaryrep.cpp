#include <iostream>
using namespace std;

void printBinaryNumsUntil(int N) {
    // logic: if N == 3, then we need to print 000, 001 ... 111
    // if N == 2, we need to print 00, 01, 10, 11
    // so we can continue to divide by 2 and print the reminder while
    // contuinuing to divide the quotient by 2
    int n = pow(2, N) - 1;
    while(n > 0) {
        string s;
        s.insert(0, to_string(n%2));
        cout << s << endl;
        n--;
    }
}

int main() {
    cout << "Print the binary representation of numbers until N" << endl;
    int N = 4;
    printBinaryNumsUntil(N);
    return 0;
}