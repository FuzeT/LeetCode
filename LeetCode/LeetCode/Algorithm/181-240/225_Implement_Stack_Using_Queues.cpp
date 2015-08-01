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

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		if (A.empty() && B.empty()) A.push(x);
		else if (A.empty() && !B.empty()) B.push(x);
		else if (!A.empty() && B.empty()) A.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (A.empty()){
			int length = B.size();
			for (int i = 0; i < length - 1; i++){
				int temp = B.front();
				B.pop();
				A.push(temp);
			}
			B.pop();
		}
		else{
			int length = A.size();
			for (int i = 0; i < length - 1; i++){
				int temp = A.front();
				A.pop();
				B.push(temp);
			}
			A.pop();
		}
	}

	// Get the top element.
	int top() {
		if (A.empty()){
			int length = B.size();
			for (int i = 0; i < length - 1; i++){
				int temp = B.front();
				B.pop();
				A.push(temp);
			}
			int tmp = B.front();
			B.pop();
			A.push(tmp);
			return tmp;
		}
		else{
			int length = A.size();
			for (int i = 0; i < length - 1; i++){
				int temp = A.front();
				A.pop();
				B.push(temp);
			}
			int tmp = A.front();
			A.pop();
			B.push(tmp);
			return tmp;
		}
	}

	// Return whether the stack is empty.
	bool empty() {
		return(A.empty() && B.empty());
	}
private:
	queue<int> A;
	queue<int> B;
};