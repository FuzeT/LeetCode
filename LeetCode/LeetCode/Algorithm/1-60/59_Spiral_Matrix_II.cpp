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
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> output;
		if (n == 1) { output.push_back(vector < int > {1}); return output; }
		for (int i = 0; i < n; i++){ output.push_back(vector<int>(n, 0)); }
		int num_now = 1, up = 0, left = 0, right = n - 1, down = n - 1;
		move_right(output, num_now, up, right, left, down);
		return output;
	}
	void move_right(vector<vector<int>>& output, int& num_now, int& up, int& right, int& left, int& down){
		int start_line = up, start_col = left;
		if (start_col <= right){
			while (start_col <= right){ output[start_line][start_col] = num_now; num_now++; start_col++; }
			up++;
			move_down(output, num_now, up, right, left, down);
		}
	}
	void move_down(vector<vector<int>>& output, int& num_now, int& up, int& right, int& left, int& down){
		int start_line = up, start_col = right;
		if (start_line <= down){
			while (start_line <= down){ output[start_line][start_col] = num_now; num_now++; start_line++; }
			right--;
			move_left(output, num_now, up, right, left, down);
		}
	}
	void move_left(vector<vector<int>>& output, int& num_now, int& up, int& right, int& left, int& down){
		int start_line = down, start_col = right;
		if (start_col >= left){
			while (start_col >= left){ output[start_line][start_col] = num_now; num_now++; start_col--; }
			down--;
			move_up(output, num_now, up, right, left, down);
		}
	}
	void move_up(vector<vector<int>>& output, int& num_now, int& up, int& right, int& left, int& down){
		int start_line = down, start_col = left;
		if (start_line >= up){
			while (start_line >= up){ output[start_line][start_col] = num_now; num_now++; start_line--; }
			left++;
			move_right(output, num_now, up, right, left, down);
		}
	}
};
