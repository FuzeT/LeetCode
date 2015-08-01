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
	int numDistinct(string s, string t) {
		int len_s = s.size(), len_t = t.size();
		if (len_s == 0 && len_t == 0) return 1;
		if (len_s < len_t) return 0;
		if (len_t == 0) return 1;
		vector<vector<int>> matrix;
		for (int i = 0; i <= len_t; i++){
			matrix.push_back(vector<int>(s.size() + 1, 0));
		}
		for (int i = 1; i <= len_s; i++){
			if (s[i - 1] == t[0]){
				matrix[1][i] = matrix[1][i - 1] + 1;
			}
			else matrix[1][i] = matrix[1][i - 1];
		}
		for (int i = 2; i <= len_t; i++){
			for (int j = i; j <= len_s; j++){
				if (t[i - 1] == s[j - 1]) {
					if (matrix[i - 1][j - 1] == 0) matrix[i][j] = 0;
					else matrix[i][j] = matrix[i - 1][j - 1] + matrix[i][j - 1];
				}
				else matrix[i][j] = matrix[i][j - 1];
			}
		}
		return matrix[len_t][len_s];
	}
};