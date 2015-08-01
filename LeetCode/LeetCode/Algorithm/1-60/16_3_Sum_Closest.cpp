#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) return NULL;
		int closest = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size();){
			size_t start = i + 1, end = nums.size() - 1;
			while (start < end){
				if (nums[i] + nums[start] + nums[end] == target) return target;
				else if (nums[i] + nums[start] + nums[end] < target){
					closest = abs(target - closest) < abs(target - (nums[i] + nums[start] + nums[end])) ? closest : nums[i] + nums[start] + nums[end];
					start++;
					while (start < end && nums[start] == nums[start - 1]) start++;
				}
				else{
					closest = abs(target - closest) < abs(target - (nums[i] + nums[start] + nums[end])) ? closest : nums[i] + nums[start] + nums[end];
					end--;
					while (start < end && nums[end] == nums[end + 1]) end--;
				}
			}
			i++;
			while (i < nums.size() && nums[i] == nums[i - 1]) i++;
		}
		return closest;
	}
};