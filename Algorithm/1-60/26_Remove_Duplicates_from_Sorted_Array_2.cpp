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
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		for (vector<int>::iterator start = nums.begin(); start != nums.end();){
			vector<int>::iterator next = start + 1;
			while (next != nums.end() && *next == *start)  next = nums.erase(next);
			start = next;
		}
		return nums.size();
	}
};