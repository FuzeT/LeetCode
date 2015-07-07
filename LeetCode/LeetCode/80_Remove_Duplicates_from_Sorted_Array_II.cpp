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
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int back = 0;
		int front = 0;
		while (front<nums.size() - 1){
			if (nums[front] == nums[front + 1]){
				nums[back] = nums[front];
				nums[back + 1] = nums[front];
				back += 2;
				front = find_next_position(nums, front);
				if (front == nums.size()) return back;
			}
			else{
				nums[back] = nums[front];
				front += 1;
				back += 1;
			}
		}
		if (front<nums.size()){ nums[back] = nums[front]; }
		return back + 1;
	}

	int find_next_position(vector<int>& nums, int from){
		int temp = nums[from];
		while (from<nums.size() && (nums[from] == temp)) from++;
		return from;
	}
};