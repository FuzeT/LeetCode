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
	int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;
		else if (dividend == 0) return 0;
		if (divisor == dividend) return 1;
		long long dividend_long = dividend, divisor_long = divisor;
		int flag = (dividend_long > 0) ^ (divisor_long > 0) ? -1 : 1;
		dividend_long = abs(dividend_long);
		divisor_long = abs(divisor_long);
		long long output = 0;
		while (dividend_long >= divisor_long){
			long long temp = divisor_long;
			long long count = 1;
			while (dividend_long > (temp << 1)){
				temp <<= 1;
				count <<= 1;
			}
			output += count;
			dividend_long -= temp;
		}
		output = flag == 1 ? output : -output;
		return output > INT_MAX ? INT_MAX : output;
	}
};