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
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> output;
		vector<int> temp_out;
		if (nums.size() == 0) return vector<vector<int>> {nums};
		sort(nums.begin(), nums.end());
		add_permutations(output, nums, temp_out);
		sort(output.begin(), output.end());
		auto x = unique(output.begin(), output.end());
		output.erase(x, output.end());
		return output;
	}
	void add_permutations(vector<vector<int>>& output, vector<int> nums, vector<int> already_in){
		if (nums.size() == 0){
			output.push_back(already_in);
		}
		else{
			for (int i = 0; i< nums.size(); i++){
				vector<int> new_left_vector = nums;
				vector<int> new_in_vector = already_in;
				new_in_vector.push_back(nums[i]);
				new_left_vector.erase(new_left_vector.begin() + i);
				add_permutations(output, new_left_vector, new_in_vector);
			}
		}
	}
};