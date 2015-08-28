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

class Solution {
public:
	string shortestPalindrome(string s) {
		if (s.size() < 2) return s;
		string temp = s;
		reverse(temp.begin(), temp.end());
		int i = s.size();
		for (; i > 0; i--){
			if (s.substr(0, i) == temp.substr(s.size() - i)) break;
		}
		return temp.substr(0, s.size() - i) + s;
	}
};