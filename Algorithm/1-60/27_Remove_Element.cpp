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
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int flag = 0;
		for (size_t i = 0; i<nums.size(); i++){
			if (nums[i] == val) continue;
			nums[flag++] = nums[i];
		}
		return flag;
	}
};