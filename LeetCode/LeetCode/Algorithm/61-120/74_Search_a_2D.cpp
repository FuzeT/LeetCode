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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;
		int start_row = 0;
		int end_row = m - 1;
		int mid_row;
		while (start_row <= end_row){
			mid_row = start_row + ((end_row - start_row) >> 1);
			if (matrix[mid_row][n - 1]<target){ start_row = mid_row + 1; }
			else if (matrix[mid_row][0]>target){ end_row = mid_row - 1; }
			else break;
		}
		if (start_row>end_row) return false;
		int start_col = 0;
		int end_col = n - 1;
		int mid_col;
		while (start_col <= end_col){
			mid_col = start_col + ((end_col - start_col) >> 1);
			if (matrix[mid_row][mid_col]<target){ start_col = mid_col + 1; }
			else if (matrix[mid_row][mid_col]>target){ end_col = mid_col - 1; }
			else return true;
		}
		if (start_col>end_col) return false;
	}
};