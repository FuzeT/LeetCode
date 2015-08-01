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
	string countAndSay(int n) {
		if (n == 1) return "1";
		else{
			string temp = countAndSay(n - 1);
			string after_trans = read_string(temp);
			return after_trans;
		}
	}
	string read_string(string s){
		stringstream output;
		for (int i = 0; i < s.size();){
			int repeat = 1;
			while (i<s.size() - 1 && s[i] == s[i + 1]){
				repeat++; i++;
			}
			output << repeat << s[i];
			i++;
		}
		string out;
		output >> out;
		return out;
	}
};