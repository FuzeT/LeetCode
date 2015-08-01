#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> output;
		if (n == 0)return output;
		string start = "(";
		getMore(start, '(', n, output);
		getMore(start, ')', n, output);
		return output;
	}
	void getMore(string s, char next, int n, vector<string>& output){
		if (isValid(s + next, n) == 1){
			getMore(s + next, '(', n, output);
			getMore(s + next, ')', n, output);
		}
		else if (isValid(s + next, n) == 2){
			output.push_back(s + next);
		}
	}
	int isValid(string s, int n){
		int temp = 0;
		if (s.size() > 2 * n) return 0;
		for (string::iterator i = s.begin(); i != s.end(); i++){
			if (*i == '(') temp++;
			else temp--;
			if (temp < 0) return 0;
		}
		if (s.size() == 2 * n && temp != 0) return 0;
		if (s.size() == 2 * n && temp == 0) return 2;
		return 1;
	}
};
