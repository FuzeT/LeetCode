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
	string multiply(string num1, string num2) {
		if (num1.size() == 0 || num2.size() == 0) return "";
		if (num1.size()<num2.size()) swap(num1, num2);
		vector<string> temp_out;
		for (int i = num2.size() - 1; i >= 0; i--){
			string multithisbig = multi_by_one(num1, num2[i]);
			int j = i;
			while (j<num2.size() - 1){ multithisbig = multithisbig + '0'; j++; }
			temp_out.push_back(multithisbig);
		}
		return combine_string(temp_out);
	}

	string multi_by_one(string num1, char c){
		if (c == '0' || num1.size() == 0) return "0";
		if (c>'9' || c<'0') return "0";
		else{
			int flag = 0;
			int n = c - '0';
			string new_num = "0" + num1;
			for (int i = num1.size() - 1; i >= 0; i--){
				int this_bit = num1[i] - '0';
				int result = this_bit*n;
				new_num[i + 1] = '0' + result % 10 + flag;
				flag = result / 10;
			}
			if (flag != 0) new_num[0] = '0' + flag;
			if (new_num[0] == '0' && new_num.size() != 1) new_num.erase(new_num.begin());
			return new_num;
		}
	}

	string combine_string(vector<string> s){
		string output = "";
		bool not_the_end = true;
		int index = 0;
		int flag = 0;
		while (not_the_end){
			not_the_end = false;
			int this_bit = flag;
			for (int i = 0; i<s.size(); i++){
				int length = s[i].size();
				if (length > index){
					not_the_end = true;
					int temp_num = s[i][length - index - 1] - '0';
					this_bit += temp_num;
				}
			}
			index++;
			flag = this_bit / 10;
			char add = '0' + this_bit % 10;
			output = add + output;
		}
		if (output[0] == '0'&& output.size() != 1) output.erase(output.begin());
		return output;
	}
};