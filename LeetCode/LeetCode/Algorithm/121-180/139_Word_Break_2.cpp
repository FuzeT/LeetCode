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
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		if (wordDict.size() == 0) return false;
		if (wordDict.find(s) != wordDict.end()) return true;
		vector<bool> flag(s.size() + 1, false);
		flag[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				if (flag[j] && (wordDict.find(s.substr(j, i - j)) != wordDict.end())){
					flag[i] = true;
					break;
				}
			}
		}
		return flag[s.size()];
	}
};