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
	int searchInsert(vector<int>& nums, int target) {
		size_t length = nums.size();
		if (length == 0) return 0;
		if (nums[0] > target) return 0;
		if (nums[length - 1]<target) return length;
		int right_place = find_right_place(nums, target, 0, length - 1);
		return right_place;
	}
	int find_right_place(vector<int>&nums, int target, int start, int end){
		int mid = (start + end) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target){
			if (nums[mid + 1] >= target) return mid + 1;
			else return find_right_place(nums, target, mid + 1, end);
		}
		else if (nums[mid] > target){
			if (nums[mid - 1] < target) return mid;
			else return find_right_place(nums, target, start, mid - 1);
		}
	}
};