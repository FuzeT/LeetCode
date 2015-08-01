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
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		bool flag = true;
		if ((numerator>0 && denominator<0) || (numerator<0 && denominator>0)) {
			flag = false;
		}
		long long _a = numerator;
		long long _b = denominator;
		_a = abs(_a);
		_b = abs(_b);
		long long pos = _a / _b, neg = _a % _b;
		string beforezero = trans(pos);
		if (neg == 0) {
			if (flag) return beforezero;
			else return "-" + beforezero;
		}
		string afterzero = transNeg(neg, _b);
		if (flag) return beforezero + "." + afterzero;
		else return "-" + beforezero + "." + afterzero;
	}
private:
	string trans(long long num){
		if (num == 0) return "0";
		string s = "";
		while (num != 0){
			char temp = '0' + num % 10;
			s = temp + s;
			num /= 10;
		}
		return s;
	}
	string transNeg(long long a, long long b){
		vector<int> already;
		string s = "";
		while (a != 0 && find(already.begin(), already.end(), a) == already.end()){
			already.push_back(a);
			long long temp = a * 10;
			s = s + char('0' + temp / b);
			a = temp%b;
		}
		if (a == 0) return s;
		else{
			for (int i = 0; i < already.size(); i++){
				if (already[i] == a){
					string undup = s.substr(0, i);
					string dup = s.substr(i);
					return undup + "(" + dup + ")";
				}
			}
		}
	}
};