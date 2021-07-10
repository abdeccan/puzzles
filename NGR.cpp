// A Stack based C++ program to find next
// greater element for all array elements.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void printNGR(int arr[], int n)
{
	stack<int> s;
	vector<int> v;

	// iterate for rest of the elements
	for (int i = n-1; i >= 0; i--)
	{
		if (s.empty()) {
			v.push_back(-1);
		}
		else if(s.top() > arr[i])
		{
			v.push_back(s.top());
		}
		else { // means stack not empty and s.top < arr[i]
			while (!s.empty()	&& (s.top() <= arr[i]))
			{
				s.pop();
			}
			if (s.empty()) 
				v.push_back(-1);	
			else if(s.top() > arr[i])
			{
				v.push_back(s.top());
			}
			}

		/* push arr[i] to stack so that we can find
		next greater for it */
		s.push(arr[i]);
	}

	reverse(v.begin(),v.end());
	for ( int i = 0; i < n; i++)
	cout << "   " << v[i];
	cout << endl;	
}

int main()
{
	int arr[] = { 1,3,2,4,4,5,6,6,8,7,9,8,7,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printNGR(arr, n);
	return 0;
}