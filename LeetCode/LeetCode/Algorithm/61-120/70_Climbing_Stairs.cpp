#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1) return 1;
		unordered_map<int, int> info;
		recurse_climb(n, info);
		return info[n];
	}
	int recurse_climb(int left_stairs, unordered_map<int, int>& info){
		if (info.find(left_stairs) != info.end()) return info[left_stairs];
		else{
			int count;
			if (left_stairs <= 1) { info[left_stairs] = 1; return 1; }
			count = recurse_climb(left_stairs - 1, info) + recurse_climb(left_stairs - 2, info);
			info[left_stairs] = count; return count;
		}
	}
};