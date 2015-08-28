#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		long long output = 0;
		if (x == 0) return x;
		while (x / 10 != 0){ output = output * 10 + (x % 10); x /= 10; }
		output = output * 10 + (x % 10);
		if (output > INT_MAX || output<INT_MIN) return 0;
		return output;
	}
};