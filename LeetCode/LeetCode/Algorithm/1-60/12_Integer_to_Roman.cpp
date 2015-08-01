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
	string intToRoman(int num) {
		stringstream output;
		int temp = num / 1000;
		if (temp != 0){
			output << string(temp, 'M');
		}
		num %= 1000;
		temp = num / 100;
		if (temp != 0){
			switch (temp){
			case 9: output << "CM"; break;
			case 4: output << "CD"; break;
			default: {
				if (temp<4){ output << string(temp, 'C'); }
				else{ output << "D" << string(temp - 5, 'C'); }
			}
			}
		}
		num %= 100;
		temp = num / 10;
		if (temp != 0){
			switch (temp){
			case 9: output << "XC"; break;
			case 4: output << "XL"; break;
			default: {
				if (temp<4){ output << string(temp, 'X'); }
				else{ output << "L" << string(temp - 5, 'X'); }
			}
			}
		}
		num %= 10;
		temp = num / 1;
		if (temp != 0){
			switch (temp){
			case 9: output << "IX"; break;
			case 4: output << "IV"; break;
			default: {
				if (temp<4){ output << string(temp, 'I'); }
				else{ output << "V" << string(temp - 5, 'I'); }
			}
			}
		}
		string out_final;
		output >> out_final;
		return out_final;
	}
};