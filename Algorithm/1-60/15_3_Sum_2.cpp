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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> output;
		if (nums.size() < 3) return output;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size();){
			int start = i + 1, end = nums.size() - 1;
			while (start < end){
				if (nums[i] + nums[start] + nums[end] == 0){
					output.push_back(vector < int > {nums[i], nums[start], nums[end]});
					start++; end--;
					while (end != start && nums[end] == nums[end + 1]){ end--; }
					while (end != start && nums[start] == nums[start - 1]){ start++; }
				}
				else if (nums[i] + nums[start] + nums[end] < 0){
					start++;
					while (end != start && nums[start] == nums[start - 1]){ start++; }
				}
				else{
					end--;
					while (end != start && nums[end] == nums[end + 1]){ end--; }
				}
			}
			i++;
			while (i < nums.size() && nums[i] == nums[i - 1]) i++;
		}
		return output;
	}
};