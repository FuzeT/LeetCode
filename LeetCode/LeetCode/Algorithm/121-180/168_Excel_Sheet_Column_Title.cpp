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
	string convertToTitle(int n) {
		string s;
		while (n > 0){
			int temp = n % 26;
			if (temp == 0){
				s = 'Z' + s;
				n = n / 26 - 1;
			}
			else {
				s = char(temp - 1 + 'A') + s;
				n = n / 26;
			}
		}
		return s;
	}
};