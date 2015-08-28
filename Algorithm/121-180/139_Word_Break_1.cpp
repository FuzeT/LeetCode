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
		bool flag = false;
		try_each(flag, s, wordDict, 0);
		return flag;
	}

	void try_each(bool& flag, string s, unordered_set<string>& wordDict, int index){
		if (flag) return;
		if (index == s.size()) {
			flag = true; return;
		}
		for (int i = s.size() - 1; i >= index; i--){
			if (wordDict.find(s.substr(index, i - index + 1)) != wordDict.end()){
				try_each(flag, s, wordDict, i + 1);
			}
		}
	}
};