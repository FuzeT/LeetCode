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
	uint32_t reverseBits(uint32_t n) {
		uint32_t output = 0;
		for (int i = 0; i < 32; i++){
			uint32_t temp = 1 << i;
			if (temp&n) output += (1 << (31 - i));
		}
		return output;
	}

	uint32_t reverseBits_2(uint32_t n) {
		uint32_t m = 0;
		for (int i = 0; i< 32; i++, n /= 2)
			m = (m << 1) + (n % 2);
		return m;
	}
};
