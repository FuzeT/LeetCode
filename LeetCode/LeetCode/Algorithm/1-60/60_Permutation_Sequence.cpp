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
	string getPermutation(int n, int k) {
		string output(n, '0');
		vector<int> temp_container;
		int total = 1;
		for (int i = 1; i <= n; i++){ total = total*i; temp_container.push_back(i); }
		if (k>total) return output;
		k -= 1;
		for (int i = 0; i <= n - 1; i++){
			total = total / (n - i);
			int index = k / total;
			k = k%total;
			output[i] = '0' + temp_container[index];
			temp_container.erase(temp_container.begin() + index);
		}
		return output;
	}
};