#include <iostream>
#include <string>
#include <algorithm>
#include <strstream>
#include <vector>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<long long> numbers = { 1,2,3,4,5,6 };
		if (n == 0) return 0;
		if (n <= 6) return numbers[n - 1];
		int a = 0;
		while (n>numbers.size()) {
			while ((numbers[a] * 2) <= numbers.back()) a++;
			int b = a;
			while ((numbers[b] * 3) > numbers.back()) b--;
			int c = b;
			while ((numbers[c] * 5) > numbers.back()) c--;
			numbers.push_back(min(min((numbers[a] * 2), (numbers[b+1] * 3)), (numbers[c+1] * 5)));
		}
		return numbers[n - 1];
	}
};
