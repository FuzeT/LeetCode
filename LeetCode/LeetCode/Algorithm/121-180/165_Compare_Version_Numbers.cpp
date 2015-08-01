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
	int compareVersion(string version1, string version2) {
		if (version1 == version2) return 0;
		version first = version(version1);
		version second = version(version2);
		for (int i = 0;;){
			int a, b;
			bool flag_a = false, flag_b = false;
			if (i >= first.versions.size()) {
				a = 0; flag_a = true;
			}
			else a = first.versions[i];
			if (i >= second.versions.size()) {
				b = 0; flag_b = true;
			}
			else b = second.versions[i];
			if (a == b) {
				if (flag_a&&flag_b) return 0;
				i++;
				continue;
			}
			if (a < b) return -1;
			if (a > b) return 1;
		}
	}
private:
	static int trans(string s){
		int num = 0;
		for (int i = 0; i < s.size(); i++){
			num = num * 10 + s[i] - '0';
		}
		return num;
	}

	struct version{
		vector<int> versions;
		version(string s){
			int start = 0;
			for (int i = 0; i < s.size(); i++){
				if (s[i] == '.') {
					versions.push_back(trans(s.substr(start, i - start)));
					start = i + 1;
				}
				if (i + 1 == s.size()){
					versions.push_back(trans(s.substr(start, i - start + 1)));
				}
			}
		}
	};
};