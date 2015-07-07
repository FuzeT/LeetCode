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
	double myPow(double x, int n) {
		if (n == 0) {
			return 1;
		}
		if (n < 0) {
			x = 1 / x;
			n = -n;
		}
		double res = myPow(x, n >> 1);
		return n & 1 ? x * res * res : res * res;
	}
};