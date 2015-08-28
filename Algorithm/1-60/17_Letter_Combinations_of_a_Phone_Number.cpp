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
	vector<string> letterCombinations(string digits) {
		vector<string> temp;
		if (digits.size() == 0) return temp;

		char start_char = digits[0];
		switch (start_char)
		{
		case '1':temp = { "" }; break;
		case '2':temp = { "a", "b", "c" }; break;
		case '3':temp = { "d", "e", "f" }; break;
		case '4':temp = { "g", "h", "i" }; break;
		case '5':temp = { "j", "k", "l" }; break;
		case '6':temp = { "m", "n", "o" }; break;
		case '7':temp = { "p", "q", "r", "s" }; break;
		case '8':temp = { "t", "u", "v" }; break;
		case '9':temp = { "w", "x", "y", "z" }; break;
		case '0':temp = { " " }; break;
		case '*':temp = { "*" }; break;
		case '#':temp = { "#" }; break;
		default: temp = { "" };
		}
		if (digits.size() == 1) return temp;
		else{
			vector<string> output;
			vector<string> New_temp = letterCombinations(digits.substr(1, digits.size() - 1));
			for (auto i = temp.begin(); i != temp.end(); i++){
				for (auto j = New_temp.begin(); j != New_temp.end(); j++){
					output.push_back(*i + *j);
				}
			}
			return output;
		}
	}
};