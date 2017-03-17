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
		vector<int> front_sum(prices.size(), 0);
		vector<int> back_sum(prices.size(), 0);
		int left_min = prices[0], right_max = prices[prices.size() - 1], output = 0;
		for (int i = 1; i<prices.size(); i++){
			if (prices[i] <= left_min) { left_min = prices[i]; front_sum[i] = front_sum[i - 1]; }
			else{ front_sum[i] = max(front_sum[i - 1], prices[i] - left_min); }
		}
		for (int i = prices.size() - 2; i >= 0; i--){
			if (prices[i] >= right_max) { right_max = prices[i]; back_sum[i] = back_sum[i + 1]; }
			else{ back_sum[i] = max(back_sum[i + 1], right_max - prices[i]); }
		}
		for (int i = 0; i<prices.size() - 1; i++){
			output = max(output, front_sum[i] + back_sum[i + 1]);
		}
		if (back_sum[0]> output) return back_sum[0];
		else return output;
	}
};
