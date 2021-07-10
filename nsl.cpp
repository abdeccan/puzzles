#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> getNSL(vector<int> in) {
    stack<int> s;
    vector<int> out;
    for(auto v : in) {
        if(s.empty()) {
            out.push_back(-1);
        } else if(s.top() < v) {
            out.push_back(s.top());
        } else {
            // we need to keep popping until stack is empty
            // OR we find a smaller element
            while(!s.empty() && s.top() >= v){
                s.pop();
            }

            // repeat above 2 steps since we woudl have landed in one of
            // them
            if(s.empty()) {
                out.push_back(-1);
            } else if(s.top() < v) {
                out.push_back(s.top());
            }
        }
        s.push(v);
    }

    return out;
}

int main() {
    cout << "Print the next smaller element to the left" << endl;
    vector<int> in = {-5, 4, 3, 2 ,1};   //{1, 2, 3, 4, 5}; // {4, 1, 2, 5, 3};
    vector<int> out = getNSL(in);
    for(auto v : in) cout << v << "     " ;
    cout << endl;
    for(auto v : out) cout << v << "     " ;
    cout << endl;
    return 0;
}