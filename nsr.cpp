#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> getNSR(vector<int> in) {
    stack<int> s;
    vector<int> out;
    for(int i = in.size() - 1; i >= 0; i--) {
        if(s.empty()) {
            out.push_back(-1);
        } else if(s.top() < in[i]) {
            out.push_back(s.top());
        } else {
            // we need to keep popping until stack is empty
            // OR we find a smaller element
            while(!s.empty() && s.top() >= in[i]){
                s.pop();
            }

            // repeat above 2 steps since we woudl have landed in one of
            // them
            if(s.empty()) {
                out.push_back(-1);
            } else if(s.top() < in[i]) {
                out.push_back(s.top());
            }
        }
        s.push(in[i]);
    }

    reverse(out.begin(), out.end());

    return out;
}

int main() {
    cout << "Print the next smaller element to the right" << endl;
    vector<int> in = {5, 4, 3, 2, 1}; //{1, 2, 3, 4, 5}; // {4, 1, 2, 5, 3};
    vector<int> out = getNSR(in);
    for(auto v : in) cout << v << "     " ;
    cout << endl;
    for(auto v : out) cout << v << "     " ;
    cout << endl;
    return 0;
}