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
		string start = "(";
		vector<string> output;
		if (n == 0) return output;
		GetMore(start, '(', -0.5, 2 * n - 1, output);
		GetMore(start, ')', -0.5, 2 * n - 1, output);
		return output;
	}
	void GetMore(string s, char next, float flag, int left, vector<string>& output){
		float new_flag = float(next) - 40.5 + flag;
		if (left == 1 && new_flag == 0){ output.push_back(s + next); }
		if (left > 1 && new_flag <= 0){
			GetMore(s + next, '(', new_flag, left - 1, output);
			GetMore(s + next, ')', new_flag, left - 1, output);
		}
	}
};