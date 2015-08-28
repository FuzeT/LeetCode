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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int countPrimes(int n) {
		if (n < 2) return 0;
		int output = 0;
		vector<bool> isPrime(n, true);
		for (int i = 2; i < sqrt(n); i++){
			if (isPrime[i]){
				for (int j = i*i; j < n; j += i){
					isPrime[j] = false;
				}
			}
		}
		for (int i = 2; i < n; i++){ if (isPrime[i]) output += 1; }
		return output;
	}
};
