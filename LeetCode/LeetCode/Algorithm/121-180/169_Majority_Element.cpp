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

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		stack<int> most;
		for (int i = 0; i<nums.size();){
			if (nums[i] != nums[i + 1]) i += 2;
			else{
				if (most.empty()) most.push(nums[i]);
				else{
					if (most.top() == nums[i]) most.push(nums[i]);
					else most.pop();
				}
				i += 2;
			}
		}
		if (most.empty()) return nums[nums.size() - 1];
		else return most.top();
	}
};