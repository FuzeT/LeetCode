#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int sum_now = 0;
		int max_sum = INT_MIN;
		int index = 0;
		while (index<nums.size() && nums[index]<0) { max_sum = max(max_sum, nums[index]); index++; }
		for (; index<nums.size(); index++){
			sum_now += nums[index];
			if (sum_now<0){ max_sum = max(max_sum, sum_now); sum_now = 0; }
			else{ max_sum = max(max_sum, sum_now); }
		}
		return max_sum;
	}
};
