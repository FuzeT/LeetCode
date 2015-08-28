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
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> output;
		if (nums.size() == 0) return output;
		if (nums.size() == 1) return vector < string > {NumToStr(nums[0])};
		int start = nums[0];
		int  i = 1;
		for (; i<nums.size(); i++){
			if (nums[i] == nums[i - 1] + 1) continue;
			else{
				if (start == nums[i - 1]){ output.push_back(NumToStr(start)); start = nums[i]; }
				else{
					string s;
					s = NumToStr(start) + "->" + NumToStr(nums[i - 1]);
					output.push_back(s);
					start = nums[i];
				}
			}
		}
		if (nums[i - 1] == nums[i - 2] + 1){
			string s;
			s = NumToStr(start) + "->" + NumToStr(nums[i - 1]);
			output.push_back(s);
		}
		else{
			output.push_back(NumToStr(nums[i - 1]));
		}
		return output;
	}

	string NumToStr(long long n){
		string s;
		if (n == 0) return "0";
		bool flag = false;
		if (n < 0) {
			flag = true;
			n *= (-1);
		}
		while (n){
			s = char('0' + n % 10) + s;
			n /= 10;
		}
		return flag ? '-' + s : s;
	}
};
