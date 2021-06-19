#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    if(n < 0) return false;
    if(n < 10) return true;

    // find the number of digits
    int temp = n, d = 0;
    while(temp != 0) {
        temp = temp/10;
        d++;
    }

    for(int i = 0, cnt = 0; cnt < d; i++, cnt++) {
        if(d-i-1 == i) break;
        int p1 = pow(10,d-i-1);
        int dig1 = n/p1;
        int dig2 = 0;
        if(i == 0) dig2 = n % 10;
        else dig2 = n / pow(10, i);
        if(dig1 != dig2) return false;

        n -= dig2;
        n -= dig1 * p1;
        cout << "n is now " << n << endl;       
    }
    
    return true;  

}

int main(int argc, char ** argv) {

    int n = 0;  // 3663;   // 3(1000) 6(100) 6(10) 3(1); 363 = 3(100) 6(10) 3(1)
    cout << "Enter num " ;
    //cin >> n;
    n = 3663;
    cout << "n is " << isPalindrome(n) << endl;
    return 0;
}
