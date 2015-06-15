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
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];
		string temp_Prefix = strs[0];
		for (size_t i = 1; i<strs.size(); i++){
			size_t j = 0;
			if (strs[i].length() == 0) return "";
			for (; j<temp_Prefix.length(); j++){
				if (strs[i].length() != j && strs[i][j] == temp_Prefix[j]) continue;
				else{
					string temp = temp_Prefix.substr(0, j);
					temp_Prefix = temp;
				}
			}
		}
		return temp_Prefix;
	}
};