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
	int uniquePaths(int m, int n) {
		if (m<1 || n<1) return 0;
		if (m == 1 || n == 1) return 1;
		vector<vector<int>> temp;
		for (int i = 0; i<m; i++){ temp.push_back(vector<int>(n, 1)); }
		for (int i = 1; i<m; i++){
			for (int j = 1; j<n; j++){
				temp[i][j] = temp[i - 1][j] + temp[i][j - 1];
			}
		}
		return temp[m - 1][n - 1];
	}
};