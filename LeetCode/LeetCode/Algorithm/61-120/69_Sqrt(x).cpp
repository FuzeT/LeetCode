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
	int mySqrt(int x) {
		if (x <= 0) return 0;
		int min = 0;
		int max = x;
		unsigned long long mid;
		while (min <= max){
			mid = min + ((max - min) >> 1);
			unsigned long long temp = mid*mid;
			if (temp > x){
				max = mid - 1;
			}
			else if (temp < x){
				min = mid + 1;
			}
			else{
				return mid;
			}
		}
		return max;
	}
};