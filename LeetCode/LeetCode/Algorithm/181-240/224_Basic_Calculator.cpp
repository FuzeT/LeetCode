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
	int calculate(string s) {
		stack<int> store_num;
		stack<char> store_oper;
		for (int i = 0; i < s.size();){
			if (s[i] == ' ') { i++; continue; }
			else if (s[i] <= '9' && s[i] >= '0'){
				int temp = 0;
				while (i < s.size() && s[i] <= '9' && s[i] >= '0'){ temp = temp * 10 + s[i] - '0'; i++; }
				if (store_num.empty() || store_oper.top() == ')' || store_oper.top() == '(') {
					store_num.push(temp); continue;
				}
				else{
					if (store_oper.top() == '+'){ store_oper.pop(); temp += store_num.top(); store_num.pop(); store_num.push(temp); continue; }
					else{ store_oper.pop(); temp = store_num.top() - temp; store_num.pop(); store_num.push(temp); continue; }
				}
			}
			else if (s[i] == ')') {
				store_oper.pop();
				i++;
				if (store_oper.empty()){ continue; }
				else {
					int first = store_num.top(); store_num.pop();
					int second = store_num.top(); store_num.pop();
					if (store_oper.top() == '+'){ store_oper.pop(); store_num.push(first + second); continue; }
					else{ store_oper.pop(); store_num.push(second - first); continue; }
				}
			}
			else{ store_oper.push(s[i]); i++; continue; }
		}
		return store_num.top();
	}
};