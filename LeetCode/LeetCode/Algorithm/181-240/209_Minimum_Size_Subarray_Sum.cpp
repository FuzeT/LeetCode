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
	int minSubArrayLen_1(int s, vector<int>& nums) {
		int sum = 0, count = 0;
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 0; i--){
			sum += nums[i];
			count++;
			if (sum >= s) return count;
		}
		if (sum<s) return 0;
	}

	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int sum = 0, start = 0, length = INT_MAX;
		for (int i = 0; i < nums.size(); i++){
			sum += nums[i];
			while (sum >= s){
				length = min(length, i - start + 1);
				sum -= (nums[start++]);
			}
		}
		return length == INT_MAX ? 0 : length;
	}
};