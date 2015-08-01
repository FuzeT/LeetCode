#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1){ return s.length(); }
		int max = 0, start = 0;
		for (int i = 0; i < s.length(); i++){
			for (int j = start; j < i; j++){
				if (s[j] == s[i]){ start = j;}
			}
			max = max>(i - start + 1) ? max : (i - start + 1);
		}
		return max;
	}
};