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
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> output;
		if (nums.size() == 0) return output;
		sort(nums.begin(), nums.end());
		for (int phase = 0; phase <= nums.size(); phase++){
			vector<int> temp_output;
			add_vector(output, temp_output, nums, phase);
		}
		return output;
	}
	void add_vector(vector<vector<int>>& output, vector<int> temp_output, vector<int> left, int k){
		if (temp_output.size() == k) output.push_back(temp_output);
		else{
			for (int i = 0; i < left.size(); i++){
				vector<int> new_left = left;
				vector<int> new_temp_output = temp_output;
				new_temp_output.push_back(left[i]);
				new_left.erase(new_left.begin(), new_left.begin() + i + 1);
				add_vector(output, new_temp_output, new_left, k);
			}
		}
	}
};