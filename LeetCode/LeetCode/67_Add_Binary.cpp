#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		stringstream container;
		int m = a.size(), n = b.size();
		if (m == 0) return b;
		else if (n == 0) return a;
		int a_index = m - 1, b_index = n - 1, flag = 0;
		while (a_index >= 0 || b_index >= 0){
			int a_value, b_value, temp_sum;
			if (a_index<0) a_value = 0;
			else a_value = a[a_index] - '0';
			if (b_index<0) b_value = 0;
			else b_value = b[b_index] - '0';
			temp_sum = a_value + b_value + flag;
			if (temp_sum == 0){ flag = 0; container << '0'; }
			else if (temp_sum == 1){ flag = 0; container << '1'; }
			else if (temp_sum == 2){ flag = 1; container << '0'; }
			else{ flag = 1; container << '1'; }
			a_index--;
			b_index--;
		}
		if (a_index<0 && b_index<0 && flag == 1){ container << '1'; }
		string temp_output;
		container >> temp_output;
		string output(temp_output.rbegin(), temp_output.rend());
		return output;
	}
};