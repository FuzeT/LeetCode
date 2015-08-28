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

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int maximam = 0;
		int buy_time = prices[0];
		for (int i = 1; i<prices.size(); i++){
			if (prices[i]<buy_time) buy_time = prices[i];
			else maximam = max(maximam, prices[i] - buy_time);
		}
		return maximam;
	}
};