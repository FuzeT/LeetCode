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
	bool isHappy(int n) {
		unordered_set<int> already;
		int new_num = n;
		while (already.find(new_num) == already.end()){
			already.insert(new_num);
			int temp = 0;
			while (new_num){ temp += (new_num % 10)*(new_num % 10); new_num /= 10; }
			if (temp == 1) return true;
			else new_num = temp;
		}
		return false;
	}
};