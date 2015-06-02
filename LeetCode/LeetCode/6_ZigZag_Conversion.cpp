#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		if (s.size() == 0)return s;
		stringstream temp;
		int phase = (2 * numRows - 2);
		for (int i = 0; i < numRows; i++){
			int start = i;
			int end = phase - i;
			while (start < s.size()){
				if (i == 0 || i == numRows - 1){ temp << s[start]; start += phase; }
				else{
					temp << s[start];
					if (end < s.size()) temp << s[end];
					start += phase;
					end += phase;
				}
			}

		}
		string output;
		temp >> output;
		return output;
	}
};
