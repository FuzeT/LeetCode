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
	int maxArea(vector<int>& height) {
		vector<int>::iterator i = height.begin(), j = height.end() - 1;
		int Max_Contain = 0;
		while (i < j){
			int temp = j - i;
			Max_Contain = max(Max_Contain, int(j - i)*min(*i, *j));
			if (*i < *j) i++;
			else if (*i > *j) j--;
			else { i++; j--; }
		}
		return Max_Contain;
	}
};