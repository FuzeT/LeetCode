#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != (s1.size() + s2.size()))return false;
		if (s1.size() == 0) return s2 == s3;
		if (s2.size() == 0) return s1 == s3;
		set<pair<int, int>> temp_flag{ make_pair(0, 0) };
		for (int i = 0; i<s3.size(); i++){
			if (temp_flag.empty()) return false;
			set<pair<int, int>> new_flag;
			for (auto each_pair = temp_flag.begin(); each_pair != temp_flag.end(); each_pair++){
				int in_s1 = each_pair->first, in_s2 = each_pair->second;
				if (in_s1<s1.size() && s3[i] == s1[in_s1]){ new_flag.insert(make_pair(in_s1 + 1, in_s2)); }
				if (in_s2<s2.size() && s3[i] == s2[in_s2]){ new_flag.insert(make_pair(in_s1, in_s2 + 1)); }
			}
			temp_flag = new_flag;
		}
		return !temp_flag.empty();

	}
};