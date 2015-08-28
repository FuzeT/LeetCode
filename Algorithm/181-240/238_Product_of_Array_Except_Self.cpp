#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <math.h>
#include <inttypes.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int length = nums.size();
		vector<int> from_left(length, 0);
		vector<int> from_right(length, 0);
		int temp_left = 1, temp_right = 1;
		for (int i = 0; i<length; i++){
			temp_left *= nums[i];
			temp_right *= nums[length - i - 1];
			from_left[i] = temp_left;
			from_right[length - i - 1] = temp_right;
		}
		nums[0] = from_right[1];
		nums[length - 1] = from_left[length - 2];
		for (int i = 1; i< length - 1; i++){
			nums[i] = from_left[i - 1] * from_right[i + 1];
		}
		return nums;
	}
};