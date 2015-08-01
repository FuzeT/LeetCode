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
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> output;
		if (n == 0) return output;
		vector<int> temp_output;
		add_vector(output, temp_output, 1, n, k);
		return output;
	}

	void add_vector(vector<vector<int>>& output, vector<int> temp_output, int start, int end, int k){
		if (temp_output.size() == k) output.push_back(temp_output);
		else if ((end - start + 1) < (k - temp_output.size())) return;
		else{
			for (int i = start; i <= end; i++){
				vector<int> new_temp_output = temp_output;
				new_temp_output.push_back(i);
				add_vector(output, new_temp_output, i + 1, end, k);
			}
		}
	}
};