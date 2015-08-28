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
	bool search(vector<int>& nums, int target) {
		int m = nums.size();
		if (m == 0) return false;
		int start = 0, end = nums.size() - 1;
		while (start <= end){
			int mid = start + ((end - start) >> 1);
			if (target>nums[mid]){
				if (nums[start]<nums[mid]){ start = mid + 1; }
				else if (nums[start] == nums[mid]){
					while (start <= end&&nums[start] == nums[mid]){ start++; }
				}
				else{
					if (nums[end] >= target){ start = mid + 1; }
					else{ end = mid - 1; }
				}
			}
			else if (target<nums[mid]){
				if (nums[end]>nums[mid]){ end = mid - 1; }
				else if (nums[end] == nums[mid]){
					while (end >= start&&nums[end] == nums[mid]){ end--; }
				}
				else{
					if (nums[start] <= target){ end = mid - 1; }
					else{ start = mid + 1; }
				}
			}
			else return true;
		}
		return false;
	}
};
