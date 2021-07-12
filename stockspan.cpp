#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void getNGLIndex(vector<int> stockPrices) {
    // logic: we want to find the next greater left (ngl problem)
    // here we want to push the index instead of the val
    vector<int> out;
    stack<int> s;
    for(int i = 0; i < stockPrices.size(); i++) {
        if(s.empty()) {
            out.push_back(-1);
        } else if(stockPrices[s.top()] > stockPrices[i]) {
            out.push_back(s.top());
        } else {
            while(!s.empty() && stockPrices[s.top()] <= stockPrices[i]) {
                s.pop();
            }
            if(s.empty()) {
                out.push_back(-1);
            } else if(stockPrices[s.top()] > stockPrices[i]) {
                out.push_back(s.top());
            }
        }

        s.push(i);
    }
    
    for(int i = 0 ; i < stockPrices.size(); i++) { 
        cout <<"Index " << out[i] << "  Span " << i - out[i] << endl;
    }
}

int main() {
    cout << "Stock span problem" << endl;
    vector<int> in = {10, 8, 16, 7, 6, 8 , 9};
    getNGLIndex(in);
    return 0;
}