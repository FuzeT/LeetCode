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

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> min;
		int n = triangle.size();
		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j < triangle[i].size(); ++j) {
				triangle[i][j] += triangle[i + 1][j] < triangle[i + 1][j + 1] ? triangle[i + 1][j] : triangle[i + 1][j + 1];
			}
		}
		return triangle[0][0];
	}
};
