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
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> output;
		if (matrix.size() == 0) return output;
		int up = 0, left = 0, right = matrix[0].size() - 1, down = matrix.size() - 1;
		move_right(output, matrix, up, right, left, down);
		return output;
	}
	void move_right(vector<int>& output, vector<vector<int>>& matrix, int& up, int& right, int& left, int& down){
		int start_line = up, start_col = left;
		if (start_col <= right){
			while (start_col <= right){ output.push_back(matrix[start_line][start_col]); start_col++; }
			up++;
			move_down(output, matrix, up, right, left, down);
		}
	}
	void move_down(vector<int>& output, vector<vector<int>>& matrix, int& up, int& right, int& left, int& down){
		int start_line = up, start_col = right;
		if (start_line <= down){
			while (start_line <= down){ output.push_back(matrix[start_line][start_col]); start_line++; }
			right--;
			move_left(output, matrix, up, right, left, down);
		}
	}
	void move_left(vector<int>& output, vector<vector<int>>& matrix, int& up, int& right, int& left, int& down){
		int start_line = down, start_col = right;
		if (start_col >= left){
			while (start_col >= left){ output.push_back(matrix[start_line][start_col]); start_col--; }
			down--;
			move_up(output, matrix, up, right, left, down);
		}
	}
	void move_up(vector<int>& output, vector<vector<int>>& matrix, int& up, int& right, int& left, int& down){
		int start_line = down, start_col = left;
		if (start_line >= up){
			while (start_line >= up){ output.push_back(matrix[start_line][start_col]); start_line--; }
			left++;
			move_right(output, matrix, up, right, left, down);
		}
	}
};