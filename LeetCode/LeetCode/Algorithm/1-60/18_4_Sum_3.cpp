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
		if (nums.size() < 4) return output;
		sort(nums.begin(), nums.end());
		size_t first = 0;
		while (first < nums.size() - 3){
			size_t second = first + 1;
			while (second < nums.size() - 2){
				int two_sum_target = target - nums[first] - nums[second];
				size_t i = second + 1, j = nums.size() - 1;
				while (i < j){
					if (nums[i] + nums[j] == two_sum_target){
						output.push_back(vector < int > {nums[first], nums[second], nums[i], nums[j]});
						do{ i++; } while (i < j&& nums[i] == nums[i - 1]);
						do{ j--; } while (i < j&& nums[j] == nums[j + 1]);
					}
					else if (nums[i] + nums[j] < two_sum_target){
						do{ i++; } while (i < j&& nums[i] == nums[i - 1]);
					}
					else do{ j--; } while (i < j&& nums[j] == nums[j + 1]);
				}
				do{ second++; } while (second < nums.size() - 2 && nums[second] == nums[second - 1]);
			}
			do{ first++; } while (first < nums.size() - 3 && nums[first] == nums[first - 1]);
		}
		return output;
	}
};