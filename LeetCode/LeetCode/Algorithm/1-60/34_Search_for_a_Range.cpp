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
	vector<int> searchRange(vector<int>& nums, int target) {
		int length = nums.size();
		if (length == 0) return vector<int>{-1, -1};
		int front_index = find_first_target(nums, 0, length - 1, target);
		int last_index = find_last_target(nums, 0, length - 1, target);
		return vector < int > {front_index, last_index};
	}
	int find_first_target(vector<int>& nums, int start, int end, int target){
		int mid = (start + end) / 2;
		if (start > end)return -1;
		if (start == end){
			if (nums[start] == target){ return start; }
			else{ return -1; }
		}
		if (nums[mid]<target){
			return find_first_target(nums, mid + 1, end, target);
		}
		else if (nums[mid] > target){
			return find_first_target(nums, start, mid - 1, target);
		}
		else if (nums[mid] == target){
			int get_fronter = find_first_target(nums, start, mid - 1, target);
			return get_fronter == -1 ? mid : get_fronter;
		}
	}
	int find_last_target(vector<int>& nums, int start, int end, int target){
		int mid = (start + end) / 2;
		if (start > end)return -1;
		if (start == end){
			if (nums[start] == target){ return start; }
			else{ return -1; }
		}
		if (nums[mid]>target){
			return find_last_target(nums, start, mid - 1, target);
		}
		else if (nums[mid] < target){
			return find_last_target(nums, mid + 1, end, target);
		}
		else if (nums[mid] == target){
			int get_laster = find_last_target(nums, mid + 1, end, target);
			return get_laster == -1 ? mid : get_laster;
		}
	}
};