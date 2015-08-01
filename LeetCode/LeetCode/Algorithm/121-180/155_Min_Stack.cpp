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
#include <unordered_set>

using namespace std;

class MinStack {
public:
	void push(int x) {
		if (container.size() == 0){
			container.push_back(make_pair(x, x));
		}
		else{
			int minNow = container.back().second;
			if (x <= minNow){ container.push_back(make_pair(x, x)); }
			else{ container.push_back(make_pair(x, minNow)); }
		}
	}

	void pop() {
		container.pop_back();
	}

	int top() {
		return container.back().first;
	}

	int getMin() {
		return container.back().second;
	}
private:
	vector<pair<int, int>> container;
};