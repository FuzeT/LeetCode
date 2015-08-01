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
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int k = word.size();
		bool flag = false;
		if (k == 0) return true;
		if (m == 0) return false;
		int n = board[0].size();
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == word[0]){
					vector<vector<char>> new_board = board;
					new_board[i][j] = NULL;
					try_bfs(new_board, i, j, word, 1, flag);
					if (flag) return flag;
				}
			}
		}
		return flag;
	}

	void try_bfs(vector<vector<char>> board, int row, int col, string word, int index, bool& output){
		if (output == true) return;
		if (index == word.size()){ output = true; return; }
		char up, left, right, down;
		up = row == 0 ? NULL : board[row - 1][col];
		left = col == 0 ? NULL : board[row][col - 1];
		right = col == (board[0].size() - 1) ? NULL : board[row][col + 1];
		down = row == (board.size() - 1) ? NULL : board[row + 1][col];
		if (up == word[index]){
			vector<vector<char>> new_board = board;
			new_board[row - 1][col] = NULL;
			try_bfs(new_board, row - 1, col, word, index + 1, output);
		}
		if (left == word[index]){
			vector<vector<char>> new_board = board;
			new_board[row][col - 1] = NULL;
			try_bfs(new_board, row, col - 1, word, index + 1, output);
		}
		if (right == word[index]){
			vector<vector<char>> new_board = board;
			new_board[row][col + 1] = NULL;
			try_bfs(new_board, row, col + 1, word, index + 1, output);
		}
		if (down == word[index]){
			vector<vector<char>> new_board = board;
			new_board[row + 1][col] = NULL;
			try_bfs(new_board, row + 1, col, word, index + 1, output);
		}
	}
};