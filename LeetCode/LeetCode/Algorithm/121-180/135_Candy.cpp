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
#include <unordered_set>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.size() == 0) return 0;
		if (ratings.size() == 1) return 1;
		stack<int> to_add;
		int sum = 0, pre = 0, pre_index = 0;
		for (int i = 0; i < ratings.size() - 1; i++){
			if (isLow(ratings, i)){
				int start = 1;
				sum += start;
				while (!to_add.empty()){
					start += to_add.top();
					to_add.pop();
					sum += start;
				}
				if (start <= pre && ratings[pre_index] != ratings[pre_index + 1]){
					sum += (pre - start + 1);
				}
				pre = 1;
				pre_index = i;
			}
			else if (ratings[i] <= ratings[i + 1]){
				pre += 1;
				pre_index = i;
				sum += pre;
			}
			else if (ratings[i]>ratings[i + 1]){
				to_add.push(1);
			}
		}
		if (isLow(ratings, ratings.size() - 1)){
			int start = 1;
			sum += start;
			while (!to_add.empty()){
				start += to_add.top();
				to_add.pop();
				sum += start;
			}
			if (start <= pre && ratings[pre_index] != ratings[pre_index + 1]){
				sum += (pre - start + 1);
			}
			pre = 1;
		}
		else{ pre += 1; sum += pre; }
		return sum;
	}

	bool isLow(vector<int>& ratings, int index){
		if (index == 0) return(ratings[index] <= ratings[index + 1]);
		if (index == ratings.size() - 1) return(ratings[index] <= ratings[index - 1]);
		return ratings[index] <= ratings[index + 1] && ratings[index] <= ratings[index - 1];
	}
};