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
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		int store_row = -1, store_col = -1;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (matrix[i][j] == 0){
					if (store_row == -1){
						store_row = i;
						store_col = j;
					}
					else{
						matrix[i][store_col] = 0;
						matrix[store_row][j] = 0;
					}
				}
			}
		}
		if (store_row == -1) return;
		for (int i = 0; i < n; i++){
			if (matrix[store_row][i] == 0 && i != store_col){
				for (int j = 0; j < m; j++){ matrix[j][i] = 0; }
			}
		}
		for (int i = 0; i < m; i++){
			if (matrix[i][store_col] == 0 && i != store_row){
				for (int j = 0; j < n; j++){ matrix[i][j] = 0; }
			}
		}
		for (int i = 0; i < m; i++){
			matrix[i][store_col] = 0;
		}
		for (int i = 0; i < n; i++){
			matrix[store_row][i] = 0;
		}
	}
};