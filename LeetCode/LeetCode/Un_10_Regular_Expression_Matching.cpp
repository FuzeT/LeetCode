#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<pair<char, int>> pattern_a = remove_duplicate(build_pattern(s));
		vector<pair<char, int>> pattern_b = remove_duplicate(build_pattern(p));
		return false;

	}
private:
	vector<pair<char, int>> build_pattern(string str){
		size_t length = str.size();
		vector<pair<char, int>> output;
		for (size_t start = 0; start < length; start++){
			char temp = str[start];
			int times = 1;
			if (start < length - 1 && str[start + 1] == temp){
				while (start < length - 1 && str[start + 1] == temp){ times++; start++; }
				if (start < length && str[start + 1] == '*'){
					times -= 1;
					start++;
					output.push_back(pair<char, int>(temp, times));
					output.push_back(pair<char, int>(temp, 0));
				}
				else{
					output.push_back(pair<char, int>(temp, times));
				}
			}
			else if (start < length - 1 && str[start + 1] == '*'){
				start++;
				output.push_back(pair<char, int>(temp, 0));
			}
			else{ output.push_back(pair<char, int>(temp, times)); }
		}
		return output;
	}
	vector<pair<char, int>> remove_duplicate(vector<pair<char, int>> temp){
		vector<pair<char, int>> output;
		for (auto item = temp.begin(); item != temp.end();){
			auto pointer = item + 1;
			while (pointer != temp.end() && *pointer == *item){ pointer++; }
			output.push_back(*item);
			item = pointer;
		}
		return output;
	}
};