#include <iostream>
#include <vector>
using namespace std;

// The cost of stock on each day is given in an array A[] of size N. 
// Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.



void stockBuySell(int price[], int n) {
    int imax = INT_MIN;
    int imin = price[0];
    int maxIdx = -1, minIdx = 0;
    vector<pair<int, int>> buy_sell;
    for(int i = 1; i < n - 1; i++) {
        // keep looking for the index imax until such time the price[imax+1] < price[imax]
        if(price[i] > imax) {
            imax = price[i];
            maxIdx = i;
        }
        // keep tracking the min also so far
        if(price[i] < imin) {
            imin = price[i];
            minIdx = i;
        }
        
        if(price[i] > price[i+1]) {
            buy_sell.push_back({minIdx, maxIdx});
            imax = INT_MIN;
            maxIdx = -1;
            imin = price[i+1];
            minIdx = i + 1;
        }
    }
    
   if(price[n-1] > imax) {
       imax = price[n-1];
       maxIdx = n-1;
   }
    if(imax > imin) {
        buy_sell.push_back({minIdx, maxIdx});
    }
    
    for(auto buy_sell_i : buy_sell) {
        cout << endl << " buy = " << buy_sell_i.first << " sell = " << buy_sell_i.second ;
    }
}


int main() {
    int prices[] = { 100, 180, 260, 310, 40, 535, 695 };
    int n = 7;
    stockBuySell(prices, n);
    return 0;
}