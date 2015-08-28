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
		if (prices.size() <= 1) return 0;
		int output = 0;
		for (int i = 0; i<prices.size();){
			int temp_maximum = 0;
			while (i<prices.size() - 1 && prices[i]>prices[i + 1]) i++;
			if (i == prices.size() - 1) return output;
			int price_buy = prices[i];
			while (i<prices.size() - 1 && prices[i + 1] >= prices[i]) i++;
			if (i == prices.size() - 1) return output + prices[i] - price_buy;
			output += prices[i] - price_buy;
		}
		return output;
	}
};