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
		if (nums.size() == 0) return 0;
		int start = nums[0];
		size_t init_length = nums.size();
		for (size_t i = 1;;){
			if (i == init_length) break;
			if (nums[i] == start){
				nums.erase(nums.begin() + i);
				init_length--;
			}
			else{ start = nums[i]; i++; }
		}
		return nums.size();
	}
};