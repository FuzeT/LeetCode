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
	void nextPermutation(vector<int>& nums) {
		for (int i = nums.size() - 2;;){
			if (i < 0) {
				sort(nums.begin(), nums.end());
				break;
			}
			if (nums[i] >= nums[i + 1]){ i--; continue; }
			int j = nums.size() - 1;
			while (j > i && nums[j] <= nums[i]) j--;
			if (i == j) {
				i--;
				continue;
			}
			else{
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				sort(nums.begin() + i + 1, nums.end());
				break;
			}
		}
	}
};