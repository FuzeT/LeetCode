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
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> output;
		if (n>55) return output;
		vector<int> temp;
		generate(output, temp, n, k, 0, 1);
		return output;
	}

	void generate(vector<vector<int>>& output, vector<int>& already, int k, int n, int sum, int loc){
		if (sum>k || already.size()>n) return;
		if (sum == k){ if (already.size() == n){ output.push_back(already); } return; }
		for (int i = loc; i <= 9; i++){
			already.push_back(i);
			generate(output, already, k, n, sum + i, i + 1);
			already.pop_back();
		}
	}
};
