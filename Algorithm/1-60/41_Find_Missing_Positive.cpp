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
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0) return 1;
		for (int i = 0; i < nums.size(); i++){
			int temp = nums[i];
			while (temp <= nums.size() && temp>0 && temp != nums[temp - 1]){
				swap(temp, nums[temp - 1]);
			}
		}
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] != i + 1)return i + 1;
		}
		return nums.size() + 1;
	}
};