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
#include <inttypes.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0) return 0;
		int count = 0;
		string s;
		int temp_n = n;
		while (temp_n){ s = char(temp_n % 10 + '0') + s; temp_n /= 10; }
		for (int i = 0; i<s.size(); i++){
			if (s[i] == '0') continue;
			count += sum(n, s.size() - i - 1);
		}
		return count;
	}

	int sum(int& n, int pos){
		if (pos == 0) return n >= 1 ? 1 : 0;
		int temp_p = pos;
		int temp_n = n;
		int count;
		while (temp_p){ temp_n /= 10; temp_p--; }
		if (temp_n>1) count = pow(10, pos) + temp_n*sumTotal(pos - 1);
		else{
			count = n - pow(10, pos) + 1 + sumTotal(pos - 1);
		}
		n = n - temp_n * pow(10, pos);
		return count;
	}

	int sumTotal(int times){
		if (times == 0) return 1;
		else return (10 * sumTotal(times - 1) + pow(10, times));
	}
};
