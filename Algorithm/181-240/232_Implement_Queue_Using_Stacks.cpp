#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <math.h>
#include <inttypes.h>
#include <unordered_set>

using namespace std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		a.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (b.empty()){
			while (!a.empty()){
				int temp = a.top();
				a.pop();
				b.push(temp);
			}
		}
		b.pop();
	}

	// Get the front element.
	int peek(void) {
		if (b.empty()){
			while (!a.empty()){
				int temp = a.top();
				a.pop();
				b.push(temp);
			}
		}
		return b.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return(a.empty() && b.empty());
	}
private:
	stack<int> a;
	stack<int> b;
};