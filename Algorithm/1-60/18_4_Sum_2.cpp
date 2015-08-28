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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> output;
		int** p;
		p = new int*[nums.size()];
		for (int i = 0; i < nums.size(); i++){
			p[i] = new int[nums.size()];
		}
		if (nums.size() < 4) return output;
		sort(nums.begin(), nums.end());
		inner_move(0, nums.size() - 1, nums, output, target, p);
		return output;
	}
	void inner_move(size_t _start, size_t _end, vector<int>& nums, vector<vector<int>>& output, int target, int** viewed){
		if ((_end - _start) >= 3 && viewed[_start][_end] != 1){
			viewed[_start][_end] = 1;
			size_t _i = _start + 1, _j = _end - 1;
			while (_i < _j){
				if (nums[_start] + nums[_end] + nums[_i] + nums[_j] == target){
					output.push_back(vector < int > {nums[_start], nums[_i], nums[_j], nums[_end]});
					_i++; _j--;
					while (_i < _j && nums[_i] == nums[_i - 1]) _i++;
					while (_i < _j && nums[_j] == nums[_j + 1]) _j--;
				}
				else if (nums[_start] + nums[_end] + nums[_i] + nums[_j] < target){
					_i++;
					while (_i < _j && nums[_i] == nums[_i - 1]) _i++;
				}
				else{
					_j--;
					while (_i < _j && nums[_j] == nums[_j + 1]) _j--;
				}
			}
			size_t new_start = _start + 1, new_end = _end - 1;
			while (new_start < new_end && nums[new_start] == nums[new_start - 1]) {
				viewed[new_start][_end] = 1; new_start++;
			}
			while (new_start < new_end && nums[new_end] == nums[new_end + 1]) {
				viewed[_start][new_end] = 1; new_end--;
			}
			inner_move(new_start, _end, nums, output, target, viewed);
			inner_move(_start, new_end, nums, output, target, viewed);
		}
	}
};