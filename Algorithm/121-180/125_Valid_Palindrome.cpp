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

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() <= 1) return true;
		int i = 0, j = s.size() - 1;
		while (i<j){
			while (i<s.size() && !isAlphanumeric(s[i])) i++;
			while (j >= 0 && !isAlphanumeric(s[j])) j--;
			if (i >= j) return true;
			if (changeToCompare(s[i]) == changeToCompare(s[j])) { i++; j--; }
			else return false;
		}
		return true;
	}

	bool isAlphanumeric(char c){
		if (c < 48) return false;
		if (c > 122) return false;
		if (c > 57 && c < 65) return false;
		if (c>90 && c < 97) return false;
		return true;
	}

	char changeToCompare(char c){
		if (c <= 57) return c;
		if (c >= 97) return c - 32;
	}
};