#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() == 0) return true;
		if (s1.size() == 1) return s1 == s2;
		if (s1 == s2) return true;
		int mid = s2.size() >> 1;
		if (s2.size() % 2){
			if (isScramble(string(s1.begin(), s1.begin() + mid), string(s2.begin(), s2.begin() + mid)) == true &&
				isScramble(string(s1.begin() + mid, s1.end()), string(s2.begin() + mid, s2.end())) == true) return true;
			if (isScramble(string(s1.begin() + mid + 1, s1.end()), string(s2.begin(), s2.begin() + mid)) == true &&
				isScramble(string(s1.begin(), s1.begin() + mid + 1), string(s2.begin() + mid, s2.end())) == true) return true;
			return false;
		}
		else{
			if (isScramble(string(s1.begin(), s1.begin() + mid), string(s2.begin(), s2.begin() + mid)) == true &&
				isScramble(string(s1.begin() + mid, s1.end()), string(s2.begin() + mid, s2.end())) == true) return true;
			if (isScramble(string(s1.begin(), s1.begin() + mid), string(s2.begin() + mid, s2.end())) == true &&
				isScramble(string(s1.begin() + mid, s1.end()), string(s2.begin(), s2.begin() + mid)) == true) return true;
			return false;
		}
	}
};