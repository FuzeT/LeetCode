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
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size()<2) return false;
		unordered_map<int, int> dict;
		for (int i = 0; i<nums.size(); i++){
			if (dict.find(nums[i]) == dict.end()) dict[nums[i]] = 0;
			else return true;
		}
		return false;
	}
};