#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() == 0) return 0;
		stack<long long> temp;
		for (int i = 0; i<tokens.size(); i++){
			if (isNum(tokens[i])){
				temp.push(trans(tokens[i]));
				continue;
			}
			else{
				long long first = temp.top();
				temp.pop();
				long long second = temp.top();
				temp.pop();
				if (tokens[i] == "+") temp.push(first + second);
				else if (tokens[i] == "-") temp.push(second - first);
				else if (tokens[i] == "*") temp.push(second*first);
				else if (tokens[i] == "/") temp.push(second / first);
			}
		}
		return temp.top();
	}

	bool isNum(string s){
		return !(s == "+" || s == "-" || s == "*" || s == "/");
	}

	long long trans(string s){
		long long num = 0;
		if (s[0] == '-'){
			for (int i = 1; i<s.size(); i++){
				num = num * 10 + s[i] - '0';
			}
			return num*(-1);
		}
		else if (s[0] == '+'){
			for (int i = 1; i<s.size(); i++){
				num = num * 10 + s[i] - '0';
			}
			return num;
		}
		else{
			for (int i = 0; i<s.size(); i++){
				num = num * 10 + s[i] - '0';
			}
			return num;
		}
	}
};