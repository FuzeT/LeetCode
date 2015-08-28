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
	void sortColors(vector<int>& nums) {
		int length = nums.size();
		if (length <= 1) return;
		int start = 0, end = length - 1;
		for (int i = start; i <= end;){
			if (start<end){
				put_it_right(nums, start, end, i);
			}
			else return;
		}
	}
	void put_it_right(vector<int>& nums, int& start, int& end, int& index){
		if (nums[index] == 0){
			int new_position = find_left(nums, start);
			if (new_position >= index) {
				index = new_position; start = new_position;
			}
			else { swap(nums[new_position], nums[index]); put_it_right(nums, start, end, index); }
		}
		else if (nums[index] == 2){
			int new_position = find_right(nums, end);
			if (new_position <= index) {
				index = new_position; end = new_position;
			}
			else{ swap(nums[new_position], nums[index]); put_it_right(nums, start, end, index); }
		}
		else if (nums[index] == 1){
			index++;
		}
	}

	int find_left(vector<int> nums, int start){
		for (int i = start; i < nums.size(); i++){
			if (nums[i] == 0) continue;
			else return i;
		}
		return nums.size();
	}

	int find_right(vector<int> nums, int end){
		for (int i = end; i >= 0; i--){
			if (nums[i] == 2) continue;
			else return i;
		}
		return -1;
	}
};