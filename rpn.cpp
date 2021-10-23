#include <iostream>
#include <stack>
#include <vector>
using namespace std;

inline bool isOperator(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return true;
    return false;
}

inline bool isNum(string s)
{
    if (isOperator(s))
        return false;

    bool isNum = true;
    try
    {
        int num = stoi(s);
    }
    catch (std::exception &)
    {
        isNum = false;
    }

    return isNum;
}

inline int calc(int n1, int n2, string op)
{
    if (op == "+")
        return n2 + n1;
    else if (op == "-")
        return n2 - n1;
    else if (op == "*")
        return n2 * n1;
    else if (op == "/")
        return n2 / n1;
    return 1;
}

int evalRPN(vector<string> &tokens)
{
    stack<int> nums;
    for (auto s : tokens)
    {
        if (isOperator(s) && !nums.empty())
        {
            int op1 = nums.top();
            nums.pop();
            int op2 = nums.top();
            nums.pop();
            int tmp = calc(op1, op2, s);
            //cout << "op1 = " << op1 << " op2 = " << op2 << "op = " << s << " tmp = " << tmp << endl;
            nums.push(tmp);
        }
        else if (isNum(s))
        {
            nums.push(stoi(s));
        }
    }

    int ans = 0;
    if (!nums.empty())
    {
        ans = nums.top();
        nums.pop();
    }

    return ans;
}

int main()
{
    cout << "RPN evaluator" << endl;

    vector<string> rpn1 = {"2", "1", "+", "3", "*"};
    vector<string> rpn2 = {"4", "13", "5", "/", "+"};
    vector<string> rpn3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "rpn1 = " << evalRPN(rpn1) << endl;
    cout << "rpn2 = " << evalRPN(rpn2) << endl;
    cout << "rpn3 = " << evalRPN(rpn3) << endl;
    return 0;
}