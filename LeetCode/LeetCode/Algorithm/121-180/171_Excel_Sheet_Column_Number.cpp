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
	int titleToNumber(string s) {
		if (s.size() == 0) return 0;
		else if (s.size() == 1) return s[0] - 'A' + 1;
		else{
			int num = 0;
			for (int i = 0; i < s.size(); i++){
				int temp = s[i] - 'A' + 1;
				num = num * 26 + temp;
			}
			return num;
		}
	}
};