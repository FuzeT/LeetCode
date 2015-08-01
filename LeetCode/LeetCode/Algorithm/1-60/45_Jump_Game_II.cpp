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
	int jump(vector<int>& nums) {
		size_t length = nums.size();
		if (length <= 1) return 1;
		int index_now = 0;
		int jump_count = 0;
		int new_index = 0;
		while (new_index<length){
			new_index = get_best_index(nums, index_now);
			if (new_index == -1) return 0;
			else if (new_index == -2) return ++jump_count;
			else{
				jump_count++;
				index_now = new_index;
			}
		}
	}

	int get_best_index(vector<int>& nums, int index_before){
		int new_index = 0;
		int new_phase = 0;
		int max_phase = index_before;
		for (int phase = index_before; phase <= (nums[index_before] + index_before); phase++){
			if (phase >= nums.size() - 1) return -2;
			new_phase = phase + nums[phase];
			if (new_phase>max_phase){
				new_index = phase;
				max_phase = new_phase;
			}
		}
		if (max_phase == index_before) return -1;
		else return new_index;
	}
};