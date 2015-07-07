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
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int flag = 1;
		for (size_t i = 1; i < nums.size(); ++i){
			if (nums[i] == nums[i - 1])
				continue;
			else nums[flag++] = nums[i];
		}
		return flag;
	}
};