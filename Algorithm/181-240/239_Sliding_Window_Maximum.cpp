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

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		multiset<int> window;
		vector<int> output;
		if (nums.size() == 0) return output;
		int front = 0;
		for (int i = 0; i < k; i++){ window.insert(nums[i]); }
		output.push_back(*(--window.end()));
		for (int i = k; i < nums.size(); i++){
			window.erase(window.find(nums[front]));
			window.insert(nums[i]);
			front++;
			output.push_back(*(--window.end()));
		}
		return output;
	}
};