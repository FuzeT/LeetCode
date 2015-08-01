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
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		if (grid.size() == 0) return count;
		for (int i = 0; i<grid.size(); i++){
			for (int j = 0; j<grid[0].size(); j++){
				if (grid[i][j] == '1'){ count += 1; dfs_change(grid, i, j); }
			}
		}
		return count;
	}

	void change_it(vector<vector<char>>& grid, int row, int col){
		queue<pair<int, int>> to_change;
		to_change.push(make_pair(row, col));
		while (!to_change.empty()){
			int a = to_change.front().first, b = to_change.front().second;
			to_change.pop();
			grid[a][b] = '0';
			if (a + 1<grid.size() && grid[a + 1][b] == '1') to_change.push(make_pair(a + 1, b));
			if (b + 1<grid[0].size() && grid[a][b + 1] == '1') to_change.push(make_pair(a, b + 1));
		}
	}

	void dfs_change(vector<vector<char>>& grid, int row, int col){
		grid[row][col] = '0';
		if (row + 1 < grid.size() && grid[row + 1][col] == '1') dfs_change(grid, row + 1, col);
		if (col + 1 < grid[0].size() && grid[row][col + 1] == '1') dfs_change(grid, row, col + 1);
		if (row - 1 >= 0 && grid[row - 1][col] == '1') dfs_change(grid, row - 1, col);
		if (col - 1 >= 0 && grid[row][col - 1] == '1') dfs_change(grid, row, col - 1);
	}
};