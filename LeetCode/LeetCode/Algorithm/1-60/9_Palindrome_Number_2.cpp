#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
			return false;
		int z = x;
		long y = 0;
		while (z != 0)
		{
			y = y * 10 + z % 10;
			z = z / 10;
		}
		if (y>INT_MAX || y<INT_MIN || x != y)
			return false;
		else
			return true;
	}
};
