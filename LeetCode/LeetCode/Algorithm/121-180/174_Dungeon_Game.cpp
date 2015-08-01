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
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.size() == 0) return 0;
		int row = dungeon.size(), col = dungeon[0].size();
		vector<vector<long long>> minimum_health(row, vector<long long>(col, 0));
		minimum_health[row - 1][col - 1] = 1 - (long long)(dungeon[row - 1][col - 1]);
		if (minimum_health[row - 1][col - 1] < 1) minimum_health[row - 1][col - 1] = 1;
		for (int i = col - 2; i >= 0; i--){
			minimum_health[row - 1][i] = minimum_health[row - 1][i + 1] - (long long)(dungeon[row - 1][i]);
			if (minimum_health[row - 1][i] < 1) minimum_health[row - 1][i] = 1;
		}
		for (int i = row - 2; i >= 0; i--){
			minimum_health[i][col - 1] = minimum_health[i + 1][col - 1] - (long long)(dungeon[i][col - 1]);
			if (minimum_health[i][col - 1] < 1) minimum_health[i][col - 1] = 1;
		}
		for (int i = row - 2; i >= 0; i--){
			for (int j = col - 2; j >= 0; j--){
				long long from_down = minimum_health[i + 1][j] - (long long)(dungeon[i][j]);
				long long from_right = minimum_health[i][j + 1] - (long long)(dungeon[i][j]);
				minimum_health[i][j] = min(from_down, from_right);
				if (minimum_health[i][j] < 1) minimum_health[i][j] = 1;
			}
		}
		return minimum_health[0][0];
	}
};