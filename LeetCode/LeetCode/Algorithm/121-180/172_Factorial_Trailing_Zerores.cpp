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
#include <unordered_set>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int zeros = 0;
		while (n) {
			zeros += n / 5;
			n /= 5;
		}
		return zeros;
	}
};