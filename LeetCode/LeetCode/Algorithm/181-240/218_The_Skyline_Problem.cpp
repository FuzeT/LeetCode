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
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> output;
		vector<vector<int>> temp;
		if (buildings.size() == 0) return output;
		temp = divide(buildings, 0, buildings.size() - 1);
		output.push_back(make_pair(temp[0][0], temp[0][2]));
		for (int i = 1; i < temp.size(); i++){
			if (temp[i][0] != temp[i - 1][1]){ output.push_back(make_pair(temp[i - 1][1], 0)); }
			output.push_back(make_pair(temp[i][0], temp[i][2]));
		}
		output.push_back(make_pair(temp.back()[1], 0));
		return output;
	}

	vector<vector<int>> divide(vector<vector<int>>& buildings, int start, int end){
		vector<vector<int>> output;
		if (start == end) return vector < vector<int> > {buildings[start]};
		int mid = (start + end) / 2;
		vector<vector<int>> left = divide(buildings, start, mid);
		vector<vector<int>> right = divide(buildings, mid + 1, end);
		return combine(left, right);
	}

	vector<vector<int>> combine(vector<vector<int>> a, vector<vector<int>> b){
		if (a.size() == 0) return b;
		else if (b.size() == 0) return a;
		vector<vector<int>> after;
		auto temp_a = a.begin();
		auto temp_b = b.begin();
		while (temp_a != a.end() && temp_b != b.end()){
			if ((*temp_a)[1] < (*temp_b)[0]){
				after.push_back((*temp_a));
				temp_a++;
				continue;
			}
			else if ((*temp_a)[0] > (*temp_b)[1]){
				after.push_back((*temp_b));
				temp_b++;
				continue;
			}
			if ((*temp_a)[2] == (*temp_b)[2]){
				vector<int> temp;
				temp.push_back(min((*temp_a)[0], (*temp_b)[0]));
				temp.push_back(min((*temp_a)[1], (*temp_b)[1]));
				temp.push_back((*temp_b)[2]);
				after.push_back(temp);
				if ((*temp_a)[1] == (*temp_b)[1]){
					temp_a++;
					temp_b++;
					continue;
				}
				else if ((*temp_a)[1] > (*temp_b)[1]){
					(*temp_a)[0] = (*temp_b)[1];
					temp_b++;
					continue;
				}
				else{
					(*temp_b)[0] = (*temp_a)[1];
					temp_a++;
					continue;
				}
			}
			else{
				int _1 = min((*temp_a)[0], (*temp_b)[0]), _2 = max((*temp_a)[0], (*temp_b)[0]), _3 = min((*temp_a)[1], (*temp_b)[1]), _4 = max((*temp_a)[1], (*temp_b)[1]);
				int _5 = max((*temp_a)[2], (*temp_b)[2]);
				if (_1 == _2&&_3 == _4){
					after.push_back(vector < int > {_1, _3, _5});
					temp_a++;
					temp_b++;
					continue;
				}
				if (_1 == _2){
					if (_1 == (*temp_a)[0]) after.push_back(vector < int > {_1, _3, _5});
					else after.push_back(vector < int > {_1, _3, _5});
					if ((*temp_b)[1] > (*temp_a)[1]){ (*temp_b)[0] = _3; temp_a++; continue; }
					else{ (*temp_a)[0] = _3; temp_b++; continue; }
				}
				if (_3 == _4){
					if (_1 == (*temp_a)[0]) after.push_back(vector < int > {_1, _2, (*temp_a)[2]});
					else after.push_back(vector < int > {_1, _2, (*temp_b)[2]});
					after.push_back(vector < int > {_2, _4, _5});
					temp_a++;
					temp_b++;
					continue;
				}
				else{
					if (_1 == (*temp_a)[0]) after.push_back(vector < int > {_1, _2, (*temp_a)[2]});
					else after.push_back(vector < int > {_1, _2, (*temp_b)[2]});
					after.push_back(vector < int > {_2, _3, _5});
					if ((*temp_b)[1] > (*temp_a)[1]){ (*temp_b)[0] = _3; temp_a++; continue; }
					else{ (*temp_a)[0] = _3; temp_b++; continue; }
				}
			}
		}
		while (temp_b != b.end()){ after.push_back(*temp_b); temp_b++; }
		while (temp_a != a.end()){ after.push_back(*temp_a); temp_a++; }
		vector<vector<int>> output{ after[0] };
		for (int i = 1; i < after.size(); i++){
			if (after[i][2] == output.back()[2] && after[i][0] == output.back()[1]) output.back()[1] = after[i][1];
			else output.push_back(after[i]);
		}
		return output;
	}
};