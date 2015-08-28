#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long output = 0;
		int flag = 0;
		size_t i = 0;
		while (str[i] == ' ') i++;
		if (str[i] == '+') { flag = 1; i++; }
		else if (str[i] == '-') { flag = -1; i++; }
		else if (isNum(str[i])) { if (flag == 0) flag = 1; }
		if (isNum(str[i])){
			if (flag == 0) flag = 1;
			output = int(str[i]) - int('0');
			while (i < str.size() - 1 && isNum(str[i + 1])){
				output = output * 10 + int(str[i + 1]) - int('0');
				if ((output*flag)>INT_MAX) return INT_MAX;
				else if ((output*flag)<INT_MIN) return INT_MIN;
				i++;
			}
			return getOutput(output, flag);
		}
		else return 0;
	}
private:
	int getOutput(long long output, int flag){
		output *= flag;
		if (output>INT_MAX) return INT_MAX;
		else if (output<INT_MIN) return INT_MIN;
		else return output;
	}
	bool isNum(char c){
		return (c >= '0' && c <= '9');
	}
};