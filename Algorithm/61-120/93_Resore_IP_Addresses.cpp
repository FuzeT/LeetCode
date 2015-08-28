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
	vector<string> restoreIpAddresses(string s) {
		vector<string> output;
		if (s.size() == 0) return output;
		string temp_output;
		helper(output, s, 0, 1, temp_output);
		return output;
	}

	void helper(vector<string>& output, string s, int start, int flag, string already){
		if ((s.size() - start)>((5 - flag) * 3)) return;
		if ((s.size() - start)<((5 - flag) * 1)) return;
		if (flag == 5) output.push_back(already.substr(0, already.size() - 1));
		if (s[start] == '0') helper(output, s, start + 1, flag + 1, already + "0.");
		else{
			string one_flag = s.substr(start, 1), two_flag = s.substr(start, 2), three_flag = s.substr(start, 3);
			helper(output, s, start + 1, flag + 1, already + one_flag + ".");
			helper(output, s, start + 2, flag + 1, already + two_flag + ".");
			if (three_flag <= "255") helper(output, s, start + 3, flag + 1, already + three_flag + ".");
		}
	}
};