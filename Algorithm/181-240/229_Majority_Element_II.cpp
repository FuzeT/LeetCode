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
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> output;
		if (nums.size() == 0) return output;
		int candi_1 = 0, candi_2 = 0, count_1 = 0, count_2 = 0;
		for (int n : nums){
			if (count_1 == 0 || candi_1 == n){ count_1++; candi_1 = n; }
			else if (count_2 == 0 || candi_2 == n){ count_2++; candi_2 = n; }
			else{ count_1--; count_2--; }
		}
		count_1 = count_2 = 0;
		for (int n : nums){
			if (n == candi_1) count_1++;
			else if (n == candi_2) count_2++;
		}
		if (count_1>nums.size() / 3) output.push_back(candi_1);
		if (count_2>nums.size() / 3) output.push_back(candi_2);
		return output;
	}
};