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
	int findMin(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int start = 0, end = nums.size() - 1;
		while (true){
			if (start == end) return nums[start];
			int mid = (start + end) >> 1;
			if (nums[mid]>nums[end]){ start = mid + 1; continue; }
			else if (nums[mid]<nums[start]){ end = mid; continue; }
			else return nums[start];
		}
	}
};