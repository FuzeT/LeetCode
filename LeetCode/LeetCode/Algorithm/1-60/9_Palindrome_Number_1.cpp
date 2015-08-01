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
		long long temp;
		int index = 0;
		if (x < 0) { return false; temp = x; temp = -temp; }
		else { temp = x; }
		long long  phase = 1;
		while (temp / phase != 0){ phase *= 10; index += 1; }
		for (int i = 0; i <= (index - i - 1); i++){
			if (getKthNum(temp, i + 1) != getKthNum(temp, index - i)) return false;
		}
		return true;
	}
private:
	int getKthNum(long long  value, int k){
		long long  phase = pow(10, k);
		if (value < phase / 10) return 0;
		else{
			long long  temp = value%phase;
			return temp / (phase / 10);
		}
	}
};
