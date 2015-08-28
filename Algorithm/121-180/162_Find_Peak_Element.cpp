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
	int findPeakElement(vector<int>& nums) {
		int length = nums.size();
		if (length == 1) return 0;
		if (nums[0]>nums[1]) return 0;
		if (nums[length - 1]>nums[length - 2]) return length - 1;
		for (int i = 1; i<length - 1;){
			if (nums[i]>nums[i - 1] && nums[i]>nums[i + 1]) return i;
			else i++;
		}
	}
};
