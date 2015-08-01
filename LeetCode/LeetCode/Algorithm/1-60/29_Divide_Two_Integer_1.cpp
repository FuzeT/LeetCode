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
		int flag = int(dividend>0) + int(divisor>0);
		string a, b;
		long long dividend_temp = dividend, divisor_temp = divisor;
		dividend_temp = dividend_temp > 0 ? dividend_temp : -dividend_temp;
		divisor_temp = divisor_temp > 0 ? divisor_temp : -divisor_temp;
		if (flag == 1) { flag = -1; a = Int_to_string(dividend_temp); b = Int_to_string(divisor_temp); }
		else{ flag = 1; a = Int_to_string(dividend_temp); b = Int_to_string(divisor_temp); }
		if (dividend_temp < divisor_temp) return 0;
		else if (divisor_temp == 1){
			long long output = flag == 1 ? dividend_temp : -dividend_temp;
			return output > INT_MAX ? INT_MAX : output;
		}
		else{
			string output = "";
			size_t i = 0;
			size_t j = b.size();
			while (j <= a.size()){
				long long temp_a = String_to_int(a.substr(i, j - i));
				int this_bit = 0;
				while (temp_a < divisor_temp&& j <= a.size()) { j++; temp_a = String_to_int(a.substr(i, j - i)); output += "0"; if (j > a.size()) return flag == 1 ? String_to_int(output) : -String_to_int(output); }
				while (temp_a >= divisor_temp){ temp_a -= divisor_temp; this_bit++; }
				if (temp_a == 0){
					i = j - 1;
					a[i] = '0';
					j++;
					output += Int_to_string(this_bit);
				}
				else{
					string temp_a_left = Int_to_string(temp_a);
					for (int pointer = temp_a_left.size() - 1; pointer >= 0; pointer--){
						a[j - temp_a_left.size() + pointer] = temp_a_left[pointer];
					}
					i = j - temp_a_left.size();
					j++;
					output += Int_to_string(this_bit);
				}
			}
			return flag == 1 ? String_to_int(output) : -String_to_int(output);
		}
	}

	string Int_to_string(long long a){
		stringstream temp;
		temp << a;
		string output;
		temp >> output;
		return output;
	}
	int String_to_int(string a){
		stringstream temp;
		temp << a;
		int output;
		temp >> output;
		return output;
	}
};