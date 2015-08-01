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
	vector<std::string> anagrams(vector<string>& strs) {
		vector<string> output;
		unordered_map<string, int> dict;
		for (int i = 0; i != strs.size(); ++i) {
			string s = strs[i];
			sort(s.begin(), s.end());
			auto iter = dict.find(s);
			if (iter != dict.end()) {
				if (iter->second != -1) {
					output.push_back(strs[iter->second]);
					iter->second = -1;
				}
				output.push_back(strs[i]);
			}
			else
				dict[s] = i;
		}
		return output;
	}
};
