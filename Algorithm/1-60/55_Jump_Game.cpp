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
	bool canJump(vector<int>& nums) {
		if (nums.size() <= 1) return true;
		int index = 0;
		for (; index<nums.size();){
			int max_path = 0;
			int new_index = 0;
			if (nums[index] == 0) return false;
			for (int temp_index = index + 1; temp_index <= index + nums[index]; temp_index++){
				if (max_path<nums[temp_index] + temp_index){ max_path = nums[temp_index] + temp_index; new_index = temp_index; };
				if (max_path >= nums.size() - 1) return true;
			}
			if (new_index == index) return false;
			index = new_index;
		}
		if (index >= nums.size() - 1) return true;
	}
};