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
	vector<int> plusOne(vector<int>& digits) {
		int m = digits.size();
		if (m == 0) return vector<int>{1};
		int flag = 1;
		for (int index = m - 1; index >= 0; index--){
			if (flag == 1){
				if (digits[index] == 9){ digits[index] = 0; flag = 1; }
				else{ digits[index]++; flag = 0; }
			}
			else{ return digits; }
		}
		if (flag == 1){ digits.insert(digits.begin(), flag); }
		return digits;
	}
};