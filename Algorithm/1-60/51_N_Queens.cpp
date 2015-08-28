#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> output;
		if (n < 1){ return output; }
		vector<vector<int>> chessboard;
		for (int i = 0; i < n; i++){ chessboard.push_back(vector<int>(n, 0)); }
		put_one_queen(output, chessboard, 0);
		return output;
	}
	void put_one_queen(vector<vector<string>>& output, vector<vector<int>> chessboard, int line){
		if (line >= chessboard.size()){ save_chessboard(output, chessboard); }
		else{
			for (int i = 0; i < chessboard.size(); i++){
				if (chessboard[line][i] == 1) continue;
				else{
					vector<vector<int>> new_chessboard = chessboard;
					new_chessboard[line][i] = 2;
					int temp_line = line + 1, left = i - 1, right = i + 1;
					while (temp_line < chessboard.size()){
						if (left >= 0) new_chessboard[temp_line][left] = 1;
						if (right<chessboard.size()) new_chessboard[temp_line][right] = 1;
						new_chessboard[temp_line][i] = 1;
						temp_line++; left--; right++;
					}
					put_one_queen(output, new_chessboard, line + 1);
				}
			}
		}
	}
	void save_chessboard(vector<vector<string>>& output, vector<vector<int>> chessboard){
		vector<string> this_solution;
		for (int i = 0; i < chessboard.size(); i++){
			stringstream this_line;
			for (int j = 0; j < chessboard.size(); j++){
				if (chessboard[i][j] == 2) this_line << "Q";
				else this_line << ".";
			}
			string temp;
			this_line >> temp;
			this_solution.push_back(temp);
		}
		output.push_back(this_solution);
	}
};
