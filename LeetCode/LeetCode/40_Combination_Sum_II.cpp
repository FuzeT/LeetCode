#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> output;
		set<vector<int>> ununiq;
		if (candidates.size() == 0) return output;
		sort(candidates.begin(), candidates.end());
		for (int i = candidates.size() - 1; i >= 0; i--){
			int temp_sum = candidates[i];
			if (temp_sum == target) { ununiq.insert(vector<int> { candidates[i] }); continue; }
			if (temp_sum > target) continue;
			vector<int> temp_output = { candidates[i] };
			find_and_add(ununiq, temp_output, candidates, temp_sum, i, target);
		}
		for (auto i = ununiq.begin(); i != ununiq.end(); i++){ output.push_back(*i); }
		return output;
	}
	void find_and_add(set<vector<int>>& output, vector<int> temp_output, vector<int>& candidates, int temp_sum, int index, int target){
		if (temp_sum > target) return;
		else if (temp_sum == target) {
			sort(temp_output.begin(), temp_output.end());
			output.insert(temp_output);
		}
		else{
			for (int i = index - 1; i >= 0; i--){
				int new_temp_sum = temp_sum + candidates[i];
				vector<int> new_temp_output = temp_output;
				new_temp_output.push_back(candidates[i]);
				find_and_add(output, new_temp_output, candidates, new_temp_sum, i, target);
			}
		}
	}
};