#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		map<char, vector<int>> dict;
		size_t max = 0, s_start = 0, duplicate = 0;
		char head = s[0];
		for (int i = 0; i<s.length(); i++){
			if (s[i] == head){
				duplicate += 1;
				max = max>duplicate ? max : duplicate;
			}
			else{
				duplicate = 1;
				head = s[i];
			}
			if (dict.find(s[i]) == dict.end()){ dict[s[i]] = vector<int>{i}; }
			else{ dict[s[i]].push_back(i); }
		}
		if (dict.size() == 1){ return s; }
		for (pair<char, vector<int>> item : dict){
			size_t i = item.second.size();
			if (i == 1) continue;
			if (item.second[i - 1] - item.second[0] + 1<max) continue;
			for (size_t start = 0; start < i; start++){
				for (size_t end = i - 1; end > start; end--){

					if ((item.second[end] - item.second[start] + 1)<max){
						break;
					}
					else if (isPalindrome(s, item.second[start], item.second[end])){
						max = item.second[end] - item.second[start] + 1;
						s_start = item.second[start];
					}
				}
			}
		}
		return s.substr(s_start, max);
	}
private:
	bool isPalindrome(string s, size_t start, size_t end){
		if (s[start] != s[end]) return false;
		else if (start == end || end - start == 1) return true;
		else return isPalindrome(s, start + 1, end - 1);
	}
};