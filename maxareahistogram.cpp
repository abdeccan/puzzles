#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> getNSRIndexes(vector<int> in) {
    // logic: we want to find the next smaller right (nsr problem)
    // here we want to push the index instead of the val
    vector<int> out;
    stack<int> s;
    for(int i = in.size() - 1; i >= 0; i--) {
        if(s.empty()) {
            out.push_back(-1);
        } else if(in[s.top()] < in[i]) {
            out.push_back(s.top());
        } else {
            while(!s.empty() && in[s.top()] >= in[i]) {
                s.pop();
            }
            if(s.empty()) {
                out.push_back(-1);
            } else if(in[s.top()] < in[i]) {
                out.push_back(s.top());
            }
        }

        s.push(i);
    }
    for(auto &v : out){
        if(v == -1) v = in.size();  // adjustment needed here
    }

    // since we are traversing from right we need to reverse the out vector
    reverse(out.begin(), out.end());

    cout << "NSR Index ";
    for(int i = 0 ; i < in.size(); i++) { 
        cout << out[i] << "     ";
    }
    cout << endl;
    return out;
}

vector<int> getNSLIndexes(vector<int> in) {
    // logic: we want to find the next smaller left (nsl problem)
    // here we want to push the index instead of the val
    vector<int> out;
    stack<int> s;
    for(int i = 0; i < in.size(); i++) {
        if(s.empty()) {
            out.push_back(-1);
        } else if(in[s.top()] < in[i]) {
            out.push_back(s.top());
        } else {
            while(!s.empty() && in[s.top()] >= in[i]) {
                s.pop();
            }
            if(s.empty()) {
                out.push_back(-1);
            } else if(in[s.top()] < in[i]) {
                out.push_back(s.top());
            }
        }

        s.push(i);
    }
    cout << "NSL Index ";
    for(int i = 0 ; i < in.size(); i++) { 
        cout << out[i] << "     ";
    }
    cout << endl;
    return out;
}


int getMAH(vector<int> in) {
    vector<int> nsrIndexes = getNSRIndexes(in);
    vector<int> nslIndexes = getNSLIndexes(in);
    int maxArea = 0, area = 0;
    for(int i = 0; i < in.size(); i++) {
        area = (nsrIndexes[i]- nslIndexes[i] - 1) * in[i];
        if(maxArea < area) maxArea = area;
    }

    return maxArea;
}

int main() {
    cout << "Max area histogram MAH" << endl;
    vector<int> in = {2,1,5,6,2,3};    //{6, 2, 5, 4, 5, 3, 6, 1, 4};
    int mah = getMAH(in);
    cout << "MAH " << mah << endl;
    return 0;
}