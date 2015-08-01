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
	int lengthOfLastWord(string s) {
		if (s.size() == 0) return 0;
		auto strip_index = s.end() - 1;
		while (*strip_index == ' '){ strip_index--; }
		s.erase(strip_index + 1, s.end());
		int start = 0;
		int end = 0;
		while (end<s.size()){
			if (s[end] == ' '){ start = end + 1; end = start; }
			else end++;
		}
		return end - start;
	}
};
