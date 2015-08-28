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
		if (triangle.size() == 0) return 0;
		else if (triangle.size() == 1) return triangle[0][0];
		int minimum = INT_MAX;
		int sum = triangle[0][0];
		recursor(triangle, 1, 0, minimum, sum);
		return minimum;
	}
	void recursor(vector<vector<int>> triangle, int level, int loc, int& minimun, int sum){
		if (level == triangle.size() - 1){
			minimun = min(minimun, sum + triangle[level][loc]);
			minimun = min(minimun, sum + triangle[level][loc + 1]);
		}
		else{
			recursor(triangle, level + 1, loc, minimun, sum + triangle[level][loc]);
			recursor(triangle, level + 1, loc + 1, minimun, sum + triangle[level][loc + 1]);
		}
	}
};