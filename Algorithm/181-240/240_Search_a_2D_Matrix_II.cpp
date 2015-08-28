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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		int i = 0;
		int j = n - 1;
		while (i >= 0 && j >= 0 && i<m &&j<n){
			if (target == matrix[i][j])
				return true;
			if (target>matrix[i][j]){
				i++;
				continue;
			}
			if (target<matrix[i][j]){
				j--;
			}
		}
		return false;
	}
};