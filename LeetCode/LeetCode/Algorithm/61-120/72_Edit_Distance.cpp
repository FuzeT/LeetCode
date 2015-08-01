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
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		if (m == 0) return n;
		if (n == 0) return m;
		vector<vector<int>> matrix;
		for (int i = 0; i <= m; i++){
			matrix.push_back(vector<int>(n + 1, 0));
		}
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (i == 1 && j == 1){
					matrix[i][j] = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
					continue;
				}
				if (i == 1){
					if (word1[i - 1] == word2[j - 1]) matrix[i][j] = j - i;
					else matrix[i][j] = matrix[i][j - 1] + 1;
					continue;
				}
				if (j == 1){
					if (word1[i - 1] == word2[j - 1]) matrix[i][j] = i - j;
					else matrix[i][j] = matrix[i - 1][j] + 1;
					continue;
				}
				int up = matrix[i - 1][j], left = matrix[i][j - 1], left_up = matrix[i - 1][j - 1];
				if (word1[i - 1] == word2[j - 1]) matrix[i][j] = min(min(up + 1, left + 1), left_up);
				else matrix[i][j] = min(min(up, left), left_up) + 1;
			}
		}
		return matrix[m][n];
	}
};