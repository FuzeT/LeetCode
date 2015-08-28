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
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		else if (nums.size() <= 2) return *max_element(nums.begin(), nums.end());;
		vector<int> first(nums.begin(), nums.end() - 1);
		vector<int> second(nums.begin() + 1, nums.end());
		return max(rob1(first), rob1(second));
	}
	int rob1(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		else if (nums.size() == 1) return nums[0];
		nums[1] = max(nums[0], nums[1]);
		for (int i = 2; i<nums.size(); i++){
			if (nums[i - 1] == nums[i - 2]) nums[i] = nums[i] + nums[i - 1];
			else{
				nums[i] = max((nums[i] + nums[i - 2]), nums[i - 1]);
			}
		}
		return nums.back();
	}
};
