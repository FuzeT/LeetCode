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
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n;
		if (m == 0) return 0;
		else if (m == 1){
			n = obstacleGrid[0].size();
			if (n == 0) return 0;
			else{
				for (auto iter = obstacleGrid[0].begin(); iter != obstacleGrid[0].end(); iter++){ if (*iter == 1) return 0; }
				return 1;
			}
		}
		else{
			if (obstacleGrid[0][0] == 1) return 0;
			for (int read_i = 0; read_i<m; read_i++){
				for (int read_j = 0; read_j<obstacleGrid[read_i].size(); read_j++){
					if (obstacleGrid[read_i][read_j] == 1) obstacleGrid[read_i][read_j] = INT_MIN;
					else obstacleGrid[read_i][read_j] = 0;
				}
			}
			for (int i = 0; i<m; i++){
				for (int j = 0; j<obstacleGrid[i].size(); j++){
					if (i == 0 && j == 0) { obstacleGrid[i][j] = 1; continue; }
					if (obstacleGrid[i][j] == INT_MIN) continue;
					int from_up, from_left;
					if (i == 0 || obstacleGrid[i - 1].size() <= j || obstacleGrid[i - 1][j] == INT_MIN) from_up = 0;
					else from_up = obstacleGrid[i - 1][j];
					if (j == 0 || obstacleGrid[i][j - 1] == INT_MIN) from_left = 0;
					else from_left = obstacleGrid[i][j - 1];
					obstacleGrid[i][j] = from_up + from_left;
				}
			}
		}
		n = obstacleGrid[m - 1].size();
		return obstacleGrid[m - 1][n - 1] == INT_MIN ? 0 : obstacleGrid[m - 1][n - 1];
	}
};