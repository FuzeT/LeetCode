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
#include <unordered_set>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0, val = 0;
		for (int i = 0; i<nums.size();){
			if (nums[i] != nums[i + 1]) i += 2;
			else{
				if (count == 0) {
					val = nums[i]; count = 1;
				}
				else{
					if (val == nums[i]) count++;
					else count--;
				}
				i += 2;
			}
		}
		if (count==0) return nums[nums.size() - 1];
		else return val;
	}
};