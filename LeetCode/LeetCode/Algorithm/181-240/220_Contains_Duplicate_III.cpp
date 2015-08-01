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
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		multiset<long long> dict;
		for (int i = 0; i < nums.size(); i++) {
			if (dict.size() == k + 1)
				dict.erase(nums[i - k - 1]);
			auto low = dict.lower_bound(nums[i] - t);
			if (low != dict.end() && abs(*low - nums[i]) <= t) return true;
			dict.insert(nums[i]);
		}
		return false;
	}
};