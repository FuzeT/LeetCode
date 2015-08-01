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
					if (store_oper.top() == '*'){ store_oper.pop(); temp *= store_num.top(); store_num.pop(); store_num.push(temp); continue; }
					else if (store_oper.top() == '/'){ store_oper.pop(); temp = store_num.top() / temp; store_num.pop(); store_num.push(temp); continue; }
					else{ store_num.push(temp); continue; }
				}
			}
			else if (s[i] == ')') {
				stack<int> temp_num;
				stack<char> temp_oper;
				while (store_oper.top() != '('){
					int number = store_num.top(); store_num.pop(); temp_num.push(number);
					char oper = store_oper.top(); store_oper.pop(); temp_oper.push(oper);
				}
				int temp = store_num.top(); store_num.pop();
				while (!temp_oper.empty()){
					if (temp_oper.top() == '+') {
						temp = temp + temp_num.top();
						temp_num.pop();
						temp_oper.pop();
					}
					else{
						temp = temp - temp_num.top();
						temp_num.pop();
						temp_oper.pop();
					}
				}
				store_num.push(temp);
			}
			else{ store_oper.push(s[i]); i++; continue; }
		}
		while (!store_oper.empty()){
			stack<int> temp_num;
			stack<char> temp_oper;
			while (!store_oper.empty()){
				int number = store_num.top(); store_num.pop(); temp_num.push(number);
				char oper = store_oper.top(); store_oper.pop(); temp_oper.push(oper);
			}
			int temp = store_num.top(); store_num.pop();
			while (!temp_oper.empty()){
				if (temp_oper.top() == '+') {
					temp = temp + temp_num.top();
					temp_num.pop();
					temp_oper.pop();
				}
				else{
					temp = temp - temp_num.top();
					temp_num.pop();
					temp_oper.pop();
				}
			}
			store_num.push(temp);
		}
		return store_num.top();
	}
};