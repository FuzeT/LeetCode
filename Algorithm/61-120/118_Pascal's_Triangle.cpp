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
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> output;
		if (numRows == 0) return output;
		else output = { vector < int > {1} };
		for (int i = 1; i < numRows; i++){
			vector<int> new_output = vector<int>(i + 1, 1);
			for (int j = 1; j < i; j++){
				new_output[j] = output[i - 1][j - 1] + output[i - 1][j];
			}
			output.push_back(new_output);
		}
		return output;
	}
};