#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> output;
		vector<int> temp;
		output.push_back(temp);
		if (nums.size() == 0) return output;
		sort(nums.begin(), nums.end());
		for (int phase = 1; phase <= nums.size(); phase++){
			set<vector<int>> dict;
			insert_to_output(dict, nums, temp, phase);
			for (auto each_vector = dict.begin(); each_vector != dict.end(); each_vector++){
				output.push_back(*each_vector);
			}
		}
		return output;
	}
	void insert_to_output(set<vector<int>>& dict, vector<int> left_nums, vector<int> already_in, int phase){
		if (already_in.size() == phase){
			if (dict.find(already_in) == dict.end()) dict.insert(already_in);
			return;
		};
		if ((phase - already_in.size())>left_nums.size()){ return; }
		for (int i = 0; i<left_nums.size();){
			int this_bit = left_nums[i];
			vector<int> new_already_in = already_in;
			vector<int> new_left_nums = left_nums;
			new_already_in.push_back(left_nums[i]);
			new_left_nums.erase(new_left_nums.begin(), new_left_nums.begin() + i + 1);
			insert_to_output(dict, new_left_nums, new_already_in, phase);
			while (i < left_nums.size() && left_nums[i] == this_bit) i++;
		}
	}
};