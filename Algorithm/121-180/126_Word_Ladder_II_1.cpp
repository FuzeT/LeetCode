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
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> output;
		if (start == end) return output;
		vector<string> new_dict;
		new_dict.push_back(start);
		for (auto iterator = dict.begin(); iterator != dict.end(); iterator++){ new_dict.push_back(*iterator); }
		new_dict.push_back(end);
		vector<vector<int>> graph(new_dict.size(), vector<int>(new_dict.size(), 0));
		for (int i = 0; i < graph.size(); i++){
			for (int j = 0; j < graph.size(); j++){
				if (i == j) graph[i][j] = 0;
				else if (j < i){ graph[i][j] = graph[j][i]; }
				else{
					if (isOneCharactorDiff(new_dict[i], new_dict[j])) graph[i][j] = 1;
					else graph[i][j] = 0;
				}
			}
		}
		vector<string> path{ start };
		add_to_vector(output, path, graph, new_dict, 0);
		return output;
	}

	void add_to_vector(vector<vector<string>>& output, vector<string> path, vector<vector<int>> path_dict, vector<string>& new_dict, int index){
		if (path_dict[index][new_dict.size() - 1] == 1){
			path.push_back(new_dict.back());
			output.push_back(path);
			return;
		}
		for (int i = 0; i < path_dict[index].size(); i++){
			if (path_dict[index][i] == 0) continue;
			else{
				vector<string> new_path = path;
				vector<vector<int>> new_path_dict = clearThisPath(path_dict, index);
				new_path.push_back(new_dict[i]);
				add_to_vector(output, new_path, new_path_dict, new_dict, i);
			}
		}
	}

	vector<vector<int>> clearThisPath(vector<vector<int>> matrix, int index){
		vector<vector<int>> new_matrix = matrix;
		for (int i = 0; i < new_matrix.size(); i++){ new_matrix[index][i] = 0; new_matrix[i][index] = 0; }
		return new_matrix;
	}

	bool isOneCharactorDiff(string s1, string s2){
		int i = 0;
		while (i<s1.size() && s1[i] == s2[i]) i++;
		i += 1;
		while (i<s1.size() && s1[i] == s2[i]) i++;
		if (i == s1.size()) return true;
		else return false;
	}
};