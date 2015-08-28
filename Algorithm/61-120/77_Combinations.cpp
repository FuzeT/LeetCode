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
		vector<int> left;
		for (int i = 1; i <= n; i++){ left.push_back(i); }
		add_vector(output, temp_output, left, k);
		return output;
	}

	void add_vector(vector<vector<int>>& output, vector<int> temp_output, vector<int> left, int k){
		if (temp_output.size() == k) output.push_back(temp_output);
		else{
			for (int i = 0; i<left.size(); i++){
				vector<int> new_left = left;
				vector<int> new_temp_output = temp_output;
				new_temp_output.push_back(left[i]);
				new_left.erase(new_left.begin(), new_left.begin() + i + 1);
				add_vector(output, new_temp_output, new_left, k);
			}
		}
	}
};