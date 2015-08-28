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
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;
		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				if (i == 0 && j == 0) continue;
				int from_up, from_left;
				if (i == 0) from_up = INT_MAX;
				else from_up = grid[i - 1][j];
				if (j == 0) from_left = INT_MAX;
				else from_left = grid[i][j - 1];
				grid[i][j] = grid[i][j] + min(from_up, from_left);
			}
		}
		return grid[m - 1][n - 1];
	}
};