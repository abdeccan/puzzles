#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    private:

    stack<int> mainstk;
    stack<int> supstk;
    
    public:

    void push(int i) {
        mainstk.push(i);
        if(supstk.empty() || i <= getMin()) {
            supstk.push(i);
        }
    }

    int pop() {
        if(mainstk.size() == 0) return -1;

        int ret = mainstk.top();
        if(ret == getMin()) {
            // need to pop from supstk also
            supstk.pop();
        }
        return ret;
    }

    int getMin() {
        if(supstk.empty()) return -1;
        return supstk.top();        
    }
};

class MinStackNoExtraSpace {
    private:

    stack<int> mainstk;
    int minEl = -1;
    
    public:

    void push(int i) {
        if(mainstk.empty()) {
            mainstk.push(i);
            minEl = i;
        }
        else if(i >= getMin()) {
            mainstk.push(i);
        } else if(i < getMin()) {
            mainstk.push(2 * i - getMin());
            minEl = i;
        }
    }

    void pop() {
        if(mainstk.size() == 0) return;

        if(mainstk.top() < getMin())    // anomaly
        {
            minEl = 2 * minEl - mainstk.top();
            mainstk.pop();
        } else if(mainstk.top() >= getMin()) {
            // no prob here
            mainstk.pop();
        }
    }

    int top() {
        if(mainstk.empty()) return -1;

        if(mainstk.top() < getMin()) {
            // anomaly
            return getMin();
        } else {
            return mainstk.top();
        }
    }

    int getMin() {
        if(mainstk.empty()) return -1;
        return minEl;
    }
};

int main() {

    MinStack min;
    min.push(18);
    min.push(19);
    min.push(29);
    min.push(15);
    min.push(15);

    cout << "min is " << min.getMin() << endl;

    cout << "popping.." << endl;
    min.pop();
    cout << "min is " << min.getMin() << endl;
    
    cout << "popping.." << endl;
    min.pop();
    cout << "min is " << min.getMin() << endl;

    cout <<" Min stack Ex" << endl;
    MinStackNoExtraSpace min1;
    min1.push(18);
    min1.push(19);
    min1.push(29);
    min1.push(15);
    min1.push(15);

    cout << "min is " << min1.getMin() << endl;

    cout << "popping.." << endl;
    min1.pop();
    cout << "min is " << min1.getMin() << endl;
    
    cout << "popping.." << endl;
    min1.pop();
    cout << "min is " << min1.getMin() << endl;

    return 0;
}