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
	int totalNQueens(int n) {
		int result = 0;
		if (n < 1){ return result; }
		vector<vector<int>> chessboard;
		for (int i = 0; i < n; i++){ chessboard.push_back(vector<int>(n, 0)); }
		put_one_queen(result, chessboard, 0);
		return result;
	}
	void put_one_queen(int& result, vector<vector<int>> chessboard, int line){
		if (line >= chessboard.size()){ result++; }
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
					put_one_queen(result, new_chessboard, line + 1);
				}
			}
		}
	}
};