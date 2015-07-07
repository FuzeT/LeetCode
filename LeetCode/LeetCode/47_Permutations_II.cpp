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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> output;
		vector<int> temp_out;
		set<vector<int>> container;
		map<int, int> dict;
		if (nums.size() == 0) return vector<vector<int>> {nums};
		for (int i = 0; i < nums.size(); i++){
			if (dict.find(nums[i]) == dict.end()){ dict[nums[i]] = 1; }
			else{ dict[nums[i]]++; }
		}
		permuteUnique_recurser(container, dict, temp_out);
		for (auto i = container.begin(); i != container.end(); i++){ output.push_back(*i); }
		return output;
	}

	void permuteUnique_recurser(set<vector<int>>& container, map<int, int> dict, vector<int> already_in){
		if (dict.size() == 1){
			vector<int> new_already_in = already_in;
			map<int, int>::iterator last_one = dict.begin();
			for (int i = 0; i < last_one->second; i++){ new_already_in.push_back(last_one->first); }
			container.insert(new_already_in);
		}
		else{
			for (auto i = dict.begin(); i != dict.end(); i++){
				map<int, int> new_dict = dict;
				vector<int> new_already_in = already_in;
				new_already_in.push_back(i->first);
				if (i->second - 1 == 0){ map<int, int>::iterator temp = new_dict.find(i->first); new_dict.erase(temp); }
				else{ new_dict[i->first] --; }
				permuteUnique_recurser(container, new_dict, new_already_in);
			}
		}
	}
};