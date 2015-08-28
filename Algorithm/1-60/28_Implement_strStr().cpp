#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		if (haystack.size() == 0 || needle.size() > haystack.size()) return -1;
		for (size_t i = 0; i<haystack.size() - needle.size() + 1;){
			size_t pointer = i;
			for (size_t j = 0;; j++){
				if (j == needle.size()) return i;
				if (haystack[pointer] != needle[j]){
					pointer = i + needle.size();
					while (pointer<haystack.size() && find_char(needle, haystack[pointer]) == -1){
						pointer++;
					}
					if (pointer<haystack.size()) { i = pointer - find_char(needle, haystack[pointer]); break; }
					else return -1;
				}
				else{
					pointer++;
				}
			}
		}
		return -1;
	}
	int find_char(string s, char c){
		if (s.size() == 0) return -1;
		for (int i = s.size() - 1; i >= 0; i--){
			if (s[i] == c) return i;
		}
		return -1;
	}
};