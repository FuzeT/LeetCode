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
		string output;
		if (s.size() == 0) return output;
		int i = s.size() - 1;
		for (; i>0; i--){
			if (isPalindrome(s, i)) break;
		}
		return reverse(s, i);
	}

	bool isPalindrome(string s, int end){
		int start = 0;
		while (start<end){
			if (s[start++] != s[end--]) return false;
		}
		return true;
	}

	string reverse(string s, int start){
		if (start == s.size() - 1) return s;
		string newString = s.substr(start + 1);
		for (int i = 0; i<newString.size(); i++){
			s = newString[i] + s;
		}
		return s;
	}
};
