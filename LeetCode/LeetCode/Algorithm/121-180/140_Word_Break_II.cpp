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
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> output;
		vector<bool> flag(s.size() + 1, false);
		if (wordDict.size() == 0) return output;
		isBreak(s, wordDict, flag);
		if (flag[s.size()] == false) return output;
		try_each(output, s, wordDict, 0, "");
		return output;
	}

	void try_each(vector<string>& output, string& s, unordered_set<string>& wordDict, int index, string already){
		if (index == s.size()) {
			output.push_back(already.substr(1));
		}
		for (int i = s.size() - 1; i >= index; i--){
			if (wordDict.find(s.substr(index, i - index + 1)) != wordDict.end()){
				try_each(output, s, wordDict, i + 1, already + " " + s.substr(index, i - index + 1));
			}
		}
	}

	void isBreak(string s, unordered_set<string>& wordDict, vector<bool>& flag) {
		flag[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				if (flag[j] && (wordDict.find(s.substr(j, i - j)) != wordDict.end())){
					flag[i] = true;
					break;
				}
			}
		}
	}
};