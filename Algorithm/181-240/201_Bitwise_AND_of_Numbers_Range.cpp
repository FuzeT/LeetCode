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
	int rangeBitwiseAnd(int m, int n) {
		if (m == n) return m;
		int output = 0;
		int flag = (1 << 30);
		while (!(flag&m || flag&n) && flag) flag >>= 1;
		while (flag) {
			if ((flag&m) == (flag&n)){ output += (flag&m); flag >>= 1; }
			else break;
		}
		return output;
	}
};