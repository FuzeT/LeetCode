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
	int numTrees(int n) {
		if (n <= 1) return 1;
		map<int, int> temp_dict;
		return recursior(n, temp_dict);
	}

	int recursior(int n, map<int, int>& dict){
		if (dict.find(n) != dict.end()) return dict[n];
		if (n <= 1) { dict[n] = 1; return 1; }
		else{
			int temp = 0;
			for (int i = 0; i<n; i++){
				temp += recursior(n - i - 1, dict) * recursior(i, dict);
			}
			dict[n] = temp;
			return temp;
		}
	}
};