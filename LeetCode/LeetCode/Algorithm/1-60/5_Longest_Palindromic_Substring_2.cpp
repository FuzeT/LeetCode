#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0) return s;
		int max_len = 1, start = 0, i = 0, j = 0, k = 0;
		for (; i < s.size();){
			if ((s.size() - i) < max_len / 2) break;
			j = k = i;
			while (k < s.size() - 1 && s[k + 1] == s[k]) k++;
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[j-1] == s[k+1]) { j--; k++; }
			if ((k - j + 1) > max_len){ max_len = k - j + 1; start = j; }
		}
		return s.substr(start, max_len);
	}
};