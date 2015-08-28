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
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		unordered_map<int, vector<int>> to_compute;
		vector<int> zeroes;
		for (int i = 0; i<nums.size();){
			vector<int> minus;
			while (i<nums.size() && nums[i] != 0){
				if (nums[i]<0) minus.push_back(i);
				i++;
			}
			zeroes.push_back(i);
			to_compute[i] = minus;
			i++;
		}
		int output = INT_MIN, start = 0;
		if (zeroes.size() == 1){ return do_compute(nums, 0, zeroes[0] - 1, to_compute[zeroes[0]]); }
		else{
			output = 0;
			for (int j = 0; j < zeroes.size(); j++){
				output = max(output, do_compute(nums, start, zeroes[j] - 1, to_compute[zeroes[j]]));
				start = zeroes[j] + 1;
			}
		}
		return output;
	}

	int do_compute(vector<int>& nums, int start, int end, vector<int>& minus){
		long long temp = 1;
		if (start >= end) return nums[start];
		if (minus.size() % 2 == 0){
			for (int k = start; k <= end; k++){ temp *= nums[k]; }
			return temp;
		}
		else if (minus.size() == 1){
			long long left = 1, right = 1;
			if (start == minus[0]) left *= nums[start];
			else { for (int k = start; k < minus[0]; k++){ left *= nums[k]; } }
			if (end == minus[0] + 1) right *= nums[end];
			else{ for (int k = minus[0] + 1; k <= end; k++){ right *= nums[k]; } }
			return max(left, right);
		}
		else{
			long long left = 1, right = 1;
			for (int k = start; k < minus.back(); k++){ left *= nums[k]; }
			for (int k = minus[0] + 1; k <= end; k++){ right *= nums[k]; }
			return max(left, right);
		}
	}
};