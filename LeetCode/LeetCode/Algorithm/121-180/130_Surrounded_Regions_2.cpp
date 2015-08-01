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
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0) return;
		int row_num = board.size(), col_num = board[0].size();
		for (int i = 0; i < row_num; i++){
			if (board[i][0] == 'O') convert_this_zone(board, i, 0);
			if (board[i][col_num - 1] == 'O') convert_this_zone(board, i, col_num - 1);
		}
		for (int j = 0; j < col_num; j++){
			if (board[0][j] == 'O') convert_this_zone(board, 0, j);
			if (board[row_num - 1][j] == 'O') convert_this_zone(board, row_num - 1, j);
		}
		for (int i = 0; i < row_num; i++){
			for (int j = 0; j < col_num; j++){
				if (board[i][j] == 'D') board[i][j] = 'O';
				else board[i][j] = 'X';
			}
		}
	}

	void convert_this_zone(vector<vector<char>>& board, int row, int col){
		board[row][col] = 'D';
		if (row + 1 < board.size() && board[row + 1][col] == 'O') convert_this_zone(board, row + 1, col);
		if (row - 1 >= 0 && board[row - 1][col] == 'O') convert_this_zone(board, row - 1, col);
		if (col + 1 < board[0].size() && board[row][col + 1] == 'O') convert_this_zone(board, row, col + 1);
		if (col - 1 >= 0 && board[row][col - 1] == 'O') convert_this_zone(board, row, col - 1);
	}
};