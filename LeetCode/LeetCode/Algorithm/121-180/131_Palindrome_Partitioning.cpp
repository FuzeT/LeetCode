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
	vector<vector<string>> partition(string s) {
		vector<vector<string>> output;
		if (s.size() == 0) return output;
		unordered_map<char, vector<int>> dict;
		for (int i = 0; i < s.size(); i++){
			if (dict.find(s[i]) == dict.end()){
				dict[s[i]] = vector < int > {i};
			}
			else{
				dict[s[i]].push_back(i);
			}
		}
		vector<string> temp_output;
		generate(output, temp_output, dict, s, 0);
		return output;
	}

	void generate(vector<vector<string>>& output, vector<string> already_in, unordered_map<char, vector<int>>& dict, string s, int index){
		if (index == s.size()) {
			output.push_back(already_in);
			return;
		}
		vector<int> pos = dict[s[index]];
		auto from = find(pos.begin(), pos.end(), index);
		for (; from != pos.end(); from++){
			if (isPalindrome(s, index, *from)){
				vector<string> new_already_in = already_in;
				new_already_in.push_back(s.substr(index, *from - index + 1));
				generate(output, new_already_in, dict, s, *from + 1);
			}
		}
	}

	bool isPalindrome(string s, int start, int end){
		if (start == end) return true;
		while (start < end){
			if (s[start] == s[end]){ start++; end--; }
			else return false;
		}
		return true;
	}
};