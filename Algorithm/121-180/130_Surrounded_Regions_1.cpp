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
			if (board[i][0] == 'O') board[i][0] = 'D';
			if (board[i][col_num - 1] == 'O') board[i][col_num - 1] = 'D';
		}
		for (int i = 0; i < col_num; i++){
			if (board[0][i] == 'O') board[0][i] = 'D';
			if (board[row_num - 1][i] == 'O') board[row_num - 1][i] = 'D';
		}
		for (int i = 1; i < row_num - 1; i++){
			for (int j = 1; j < col_num - 1; j++){
				if (board[i][j] == 'X' || board[i][j] == 'D') continue;
				else{
					set<pair<int, int>> to_change;
					if (recursor(board, i, j, to_change)){
						change_to_char(board, to_change, 'D');
					}
					else change_to_char(board, to_change, 'X');
				}
			}
		}
		for (int i = 0; i < row_num; i++){
			for (int j = 0; j < col_num; j++){
				if (board[i][j] == 'D') board[i][j] = 'O';
			}
		}
	}

	void change_to_char(vector<vector<char>>& board, set<pair<int, int>> to_change, char to_it){
		for (auto iter = to_change.begin(); iter != to_change.end(); iter++){
			board[iter->first][iter->second] = to_it;
		}
	}

	bool recursor(vector<vector<char>>& board, int row, int col, set<pair<int, int>>& to_change){
		to_change.insert(make_pair(row, col));
		board[row][col] = 'P';
		bool left, right, up, down;
		if (board[row - 1][col] == 'X' || board[row - 1][col] == 'P') up = false;
		else if (board[row - 1][col] == 'D') up = true;
		else up = recursor(board, row - 1, col, to_change);
		if (board[row + 1][col] == 'X' || board[row + 1][col] == 'P') down = false;
		else if (board[row + 1][col] == 'D') down = true;
		else down = recursor(board, row + 1, col, to_change);
		if (board[row][col - 1] == 'X' || board[row][col - 1] == 'P') left = false;
		else if (board[row][col - 1] == 'D') left = true;
		else left = recursor(board, row, col - 1, to_change);
		if (board[row][col + 1] == 'X' || board[row][col + 1] == 'P') right = false;
		else if (board[row][col + 1] == 'D') right = true;
		else right = recursor(board, row, col + 1, to_change);
		return (up || down || left || right);
	}
};