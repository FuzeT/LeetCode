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
	int romanToInt(string s) {
		int output = 0;
		for (size_t i = 0; i < s.length();){
			switch (s[i]){
			case 'M': {
				output += 1000;
				i += 1;
				break;
			}
			case 'D':{ output += 500; i += 1; break; }
			case 'C':{
				if (i < s.length() - 1 && s[i + 1] == 'M'){
					output += 900;
					i += 2;
				}
				else if (i < s.length() - 1 && s[i + 1] == 'D'){
					output += 400;
					i += 2;
				}
				else{
					output += 100;
					i += 1;
				}
				break;
			}
			case 'L': { output += 50; i += 1; break; }
			case 'X':{
				if (i < s.length() - 1 && s[i + 1] == 'C'){
					output += 90;
					i += 2;
				}
				else if (i < s.length() - 1 && s[i + 1] == 'L'){
					output += 40;
					i += 2;
				}
				else{
					output += 10;
					i += 1;
				}
				break;
			}
			case 'V':{ output += 5; i += 1; break; }
			case'I':{
				if (i < s.length() - 1 && s[i + 1] == 'X'){
					output += 9;
					i += 2;
				}
				else if (i < s.length() - 1 && s[i + 1] == 'V'){
					output += 4;
					i += 2;
				}
				else{
					output += 1;
					i += 1;
				}
				break;
			}
			}
		}
		return output;
	}

};