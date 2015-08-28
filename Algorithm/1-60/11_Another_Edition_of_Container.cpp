#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() <= 2) return 0;
		size_t start = 0, end = 0;
		size_t temp_start = 0, temp_pointer = 0;
		int max = 0, temp_max = 0;
		while (temp_pointer<(height.size()) && temp_start != temp_pointer){
			if (height[temp_pointer] >= height[temp_start]){
				temp_max = 0;
				for (int i = temp_start + 1; i<temp_pointer; i++){
					temp_max += (height[temp_start] - height[i]);
				}
				if (temp_max>max){
					max = temp_max;
					start = temp_start;
					end = temp_pointer;
				}
				temp_start = temp_pointer;
				temp_pointer = temp_start + 1;
			}
			else{
				temp_pointer += 1;
			}
		}
		return max;
	}
};
