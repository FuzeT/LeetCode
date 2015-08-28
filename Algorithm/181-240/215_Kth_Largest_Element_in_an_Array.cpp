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
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 0) return 0;
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};