#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> alpha_index(256, -1);
		int start = 0, max = 0;
		for (int i = 0; i < s.length(); i++){
			if (alpha_index[s[i]] >= start){ start = alpha_index[s[i]] + 1; }
			alpha_index[s[i]] = i;
			max = max>(i - start + 1) ? max : (i - start + 1);
		}
		return max;
	}
};