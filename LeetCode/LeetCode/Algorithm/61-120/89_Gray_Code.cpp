#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> output;
		int base = 1 << (n - 1);
		if (n == 0) return  vector<int>{0};
		if (n == 1) return vector<int>{0, 1};
		else{
			auto temp = grayCode(n - 1);
			output = temp;
			for (int i = temp.size() - 1; i >= 0; i--){
				output.push_back(temp[i] + base);
			}
			return output;
		}
	}
};