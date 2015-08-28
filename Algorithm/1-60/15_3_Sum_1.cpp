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
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<multiset<int>> output;
		set<int> belowZero, aboveZero, equalZero;
		multiset<int> all;
		for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
			all.insert(*i);
			if (*i > 0) aboveZero.insert(*i);
			else if (*i < 0) belowZero.insert(*i);
			else equalZero.insert(*i);
		}
		set<int>::iterator i = aboveZero.begin();
		while (i != aboveZero.end()){
			set<int>::iterator j = belowZero.begin();
			while (j != belowZero.end()){
				int temp = *i + *j;
				if (temp>0){
					temp = -temp;
					if (temp == *j){
						if (all.count(temp) > 1) output.insert(multiset < int > {*j, temp, temp});
					}
					else if (belowZero.find(temp) != belowZero.end()) output.insert(multiset < int > {*j, *i, temp});
				}
				else if (temp<0){
					temp = -temp;
					if (temp == *i){
						if (all.count(temp) > 1) output.insert(multiset < int > {*i, temp, temp});
					}
					else if (aboveZero.find(temp) != aboveZero.end()) output.insert(multiset < int > {*j, *i, temp});
				}
				else{
					if (equalZero.size() != 0) output.insert(multiset < int > {*j, *i, 0});
				}
				j++;
			}
			i++;
		}
		if (all.count(0)>2) output.insert(multiset < int > {0, 0, 0});
		vector<vector<int>> real_return;
		for (auto i = output.begin(); i != output.end(); i++){
			vector<int> temp;
			for (auto j = i->begin(); j != i->end(); j++) temp.push_back(*j);
			real_return.push_back(temp);
		}
		return real_return;
	}
};