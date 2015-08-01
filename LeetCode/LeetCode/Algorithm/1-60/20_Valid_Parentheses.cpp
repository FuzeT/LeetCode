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
	bool isValid(string s) {
		vector<char> temp_stack;
		for (string::iterator i = s.begin(); i != s.end(); i++){
			vector<char>::iterator pointer = temp_stack.end();
			switch (*i){
			case '(':
				temp_stack.push_back('(');
				break;
			case '{':
				temp_stack.push_back('{');
				break;
			case '[':
				temp_stack.push_back('[');
				break;
			case ')':
				pointer--;
				if (temp_stack.size() == 0 || *pointer != '(')return false;
				else{
					temp_stack.erase(pointer);
					break;
				}
			case '}':
				pointer--;
				if (temp_stack.size() == 0 || *pointer != '{')return false;
				else{
					temp_stack.erase(pointer);
					break;
				}
			case ']':
				pointer--;
				if (temp_stack.size() == 0 || *pointer != '[')return false;
				else{
					temp_stack.erase(pointer);
					break;
				}
			default:
				continue;
			}
		}
		if (temp_stack.size() != 0) return false;
		else return true;
	}
};