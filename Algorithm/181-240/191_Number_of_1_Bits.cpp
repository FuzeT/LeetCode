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
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n){
			count += (n % 2);
			n >>= 1;
		}
		return count;
	}
};
