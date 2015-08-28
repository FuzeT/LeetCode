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
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		for (int i = 1; i<nums.size(); i++){
			nums[0] ^= nums[i];
		}
		return nums[0];
	}
};