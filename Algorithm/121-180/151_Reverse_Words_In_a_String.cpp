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
	void reverseWords(string &s) {
		process(s);
		size_t length = s.size();
		if (length == 0) return;
		reverse(s, 0, length);
		size_t start = 0, end = 0;
		for (int i = 0; i<length; i++){
			if (s[i] == ' '){
				end = i;
				reverse(s, start, end);
				start = i + 1;
			}
			if (i + 1 == length){
				reverse(s, start, length);
			}
		}
	}
	void reverse(string& s, size_t start, size_t end){
		for (int j = start; j<((end + start) >> 1); j++){
			char temp = s[j];
			s[j] = s[end + start - j - 1];
			s[end + start - j - 1] = temp;
		}
	}

	void process(string &s){
		if (s.size() == 0) return;
		int front = 0, back = 0;
		bool flag = true;
		while (front < s.size()){
			if (flag && s[front] == ' '){ front++; }
			else if (s[front] != ' '){ s[back] = s[front]; flag = false; front++; back++; }
			else { flag = true; s[back] = s[front]; back++; front++; }
		}
		s.erase(s.begin() + back, s.end());
		if (s[back - 1] == ' '){ s.erase(back - 1, 1); }
	}
};
