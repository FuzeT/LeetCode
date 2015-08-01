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
	void rotate(vector<int>& nums, int k) {
		int length = nums.size();
		if (length == 0) return;
		k = k % length;
		if (k == 0) return;
		unordered_set<int> already_visited;
		int start = 0, loopTime = length, next_pos = 0, temp_val = nums[0], next_val = 0;
		while (1){
			if (already_visited.find(start) == already_visited.end()){
				already_visited.insert(start);
				next_pos = getNextPos(length, k, start);
				next_val = nums[next_pos];
				nums[next_pos] = temp_val;
				temp_val = next_val;
				start = next_pos;
			}
			else if (already_visited.find((start + 1) % length) == already_visited.end()){
				start = (start + 1) % length;
				temp_val = nums[start];
			}
			else return;
		}
	}
	int getNextPos(int length, int k, int pos){
		return(pos + k) % length;
	}
};