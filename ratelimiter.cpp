// ratelimiter.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <queue>
#include <map>
#include <iostream>
#include <timeapi.h>
using namespace std;

/*
Rate Limiter

Problem Description:
Imagine we are building an application that is used by many different customers. We want to avoid one customer being able to overload the system by sending too many requests, so we enforce a per-customer rate limit. The rate limit is defined as:
“Each customer can make X requests per 60 seconds”
Assuming that customer ID is extracted somehow from the request and provided to you, implement the following function.

// Perform rate limiting logic for provided customer ID. Return true if the
// request is allowed, and false if it is not.
boolean isRequestAllowed(int customerId)


pseudo code:

we have a customerId --> container containig the list of timestamps

pair<int, queue<int>>

00:01:00 -->
::
00:01:59 -->

00:02:00

*/

class RateLimiterBase {
public:
	bool isRequestAllowed(int customerId);

	// helper methods
};


class CRateLimitImpl : public  RateLimiterBase {
	int _interval;
	int _capacity;

	map<int, queue<long>> _reqMap;	// store customerId -- req coll

	// code to populate customers is out

public:
	CRateLimitImpl::CRateLimitImpl(int capacity, int interval) : _interval(interval), _capacity(capacity) {
		//
	}

	bool isRequestAllowed(int customerId) {
		// 
		if (_reqMap.find(customerId) == _reqMap.end())	// this means cust is not in map yet
		{
			// insert the entry
			queue<long> custTimestampQ;
			custTimestampQ.push(timeGetTime());
			_reqMap[customerId] = custTimestampQ;
			return true;
		}
		else
		{
			// the customer has already made a request
			queue<long> thisCustQ = _reqMap[customerId];
			if (thisCustQ.empty()) {
				thisCustQ.push(timeGetTime());
				_reqMap[customerId] = thisCustQ;
				return true;
			}
			else {
				// front --> [t1, t2..... tn] --> rear
				queue<long> thisCustQ = _reqMap[customerId];
				long now = timeGetTime();
				while (!thisCustQ.empty() && thisCustQ.front() - now > _interval) {
					thisCustQ.pop();	// this will trim the queue
				}

				if (thisCustQ.size() < _capacity) {
					thisCustQ.push(timeGetTime());
					return true;
				}
			}
		}
		return false;
	}

};



int main()
{

	CRateLimitImpl rImpl(5, 5000);	// 5000 ms and 5 req in that duration
	vector<int> custIds = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < 10; i++) {
		cout << "For custId " << custIds[0] << " isAllowed = " << rImpl.isRequestAllowed(custIds[0]) << endl;
		cout << "For custId " << custIds[2] << " isAllowed = " << rImpl.isRequestAllowed(custIds[2]) << endl;
		cout << "For custId " << custIds[4] << " isAllowed = " << rImpl.isRequestAllowed(custIds[4]) << endl;
		cout << "For custId " << custIds[5] << " isAllowed = " << rImpl.isRequestAllowed(custIds[5]) << endl;
	}

	return 0;
}

