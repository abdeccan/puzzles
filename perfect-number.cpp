#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int sum = 1, prod = 1;
    
    for (int i = 5; i < 1000; i++) 
    {
        sum =1; 
        prod = 1;
        for (int j = 2; j <= (i/2) ; j++)
        {
            if ( 0 == i%j )
            {
                sum = sum + j;
                prod = prod * j;
            }
        }
        
        if ( i == sum ) cout << "perfect num : " << i; 
    
    }    
    return 0;
}