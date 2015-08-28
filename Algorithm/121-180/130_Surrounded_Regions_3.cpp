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
		for (int i = 0; i < col_num; i++){
			if (board[0][i] == 'O'){
				set<pair<int, int>> to_change;
				to_change.insert(make_pair(0, i));
				browse_this_zone(board, to_change);
			}
			if (board[row_num - 1][i] == 'O'){
				set<pair<int, int>> to_change;
				to_change.insert(make_pair(row_num - 1, i));
				browse_this_zone(board, to_change);
			}
		}
		for (int j = 0; j < row_num; j++){
			if (board[j][0] == 'O'){
				set<pair<int, int>> to_change;
				to_change.insert(make_pair(j, 0));
				browse_this_zone(board, to_change);
			}
			if (board[j][col_num - 1] == 'O'){
				set<pair<int, int>> to_change;
				to_change.insert(make_pair(j, col_num - 1));
				browse_this_zone(board, to_change);
			}
		}
		for (int i = 0; i < row_num; i++){
			for (int j = 0; j < col_num; j++){
				if (board[i][j] == 'D') board[i][j] = 'O';
				else board[i][j] = 'X';
			}
		}
	}

	void browse_this_zone(vector<vector<char>>& board, set<pair<int, int>>& to_change){
		while (to_change.size() != 0){
			auto temp = to_change.begin();
			int row = temp->first, col = temp->second;
			to_change.erase(temp);
			if (row>0 && board[row - 1][col] == 'O') to_change.insert(make_pair(row - 1, col));
			if (row < board.size() - 1 && board[row + 1][col] == 'O') to_change.insert(make_pair(row + 1, col));
			if (col > 0 && board[row][col - 1] == 'O') to_change.insert(make_pair(row, col - 1));
			if (col < board[0].size() - 1 && board[row][col + 1] == 'O') to_change.insert(make_pair(row, col + 1));
			board[row][col] = 'D';
		}
	}
};