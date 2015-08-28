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

using namespace std;


class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> output;
		output = vector<int>(rowIndex + 1, 1);
		output[0] = output[rowIndex] = 1;
		for (int i = 1; i <= (rowIndex >> 1); i++){
			long long new_value = (long long)output[i - 1] * (long long)(rowIndex - i + 1) / i;
			output[i] = output[rowIndex - i] = new_value;
		}
		return output;
	}
};
