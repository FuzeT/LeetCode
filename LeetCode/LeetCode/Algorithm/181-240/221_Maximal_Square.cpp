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
	int maximalSquare(vector<vector<char>>& matrix) {
		int output = 0;
		if (matrix.size() == 0) return output;
		for (int i = 0; i<(matrix.size() - output); i++){
			for (int j = 0; j<(matrix[0].size() - output); j++){
				if (matrix[i][j] == '1') browse(output, matrix, i, j);
			}
		}
		return output*output;
	}

	void browse(int& output, vector<vector<char>>& matrix, int i, int j){
		if (i == matrix.size() - 1 || j == matrix[0].size() - 1) { output = max(output, 1); return; }
		int row = i + 1, col = j + 1;
		while (row<matrix.size() && col<matrix[0].size()){
			if (matrix[row][col] != '1') break;
			else{
				bool flag = true;
				for (int _col = j; _col < col; _col++){ if (matrix[row][_col] == '0') { flag = false; break; } }
				for (int _row = i; _row < row; _row++){ if (matrix[_row][col] == '0') { flag = false; break; } }
				if (!flag) break;
			}
			row++; col++;
		}
		output = max(output, row - i);
	}
};
