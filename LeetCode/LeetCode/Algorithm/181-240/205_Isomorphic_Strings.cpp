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
#include <inttypes.h>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, char*> dict;
		vector<char*> _s;
		for (int i = 0; i < s.size(); i++){
			if (dict.find(s[i]) == dict.end()){
				char* newChar = new char(s[i]);
				_s.push_back(newChar);
				dict[s[i]] = newChar;
			}
			else{
				_s.push_back(dict[s[i]]);
			}
		}
		for (int i = 0; i < t.size(); i++){
			*(_s[i]) = t[i];
		}
		set<char> check;
		for (auto iter = dict.begin(); iter != dict.end(); iter++){
			if (check.find(*(iter->second)) == check.end()){ check.insert(*(iter->second)); }
			else return false;
		}
		for (int i = 0; i < s.size(); i++){
			s[i] = *(_s[i]);
		}
		return s == t;
	}
};
