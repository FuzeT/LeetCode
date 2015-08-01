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
	int trap(vector<int>& height) {
		int total_sum = 0;
		if (height.size() <= 2) return total_sum;
		int start = 0;
		for (int i = 1; i < height.size();){
			if (height[i]>height[start]){
				total_sum += cout_cont(height, start, i);
				start = i;
				i += 1;
				continue;
			}
			int index = i;
			int temp_high = height[i];
			while (index < height.size() - 1 && height[index + 1] < height[index]) { index++; }
			if (index == height.size() - 1)return total_sum;
			temp_high = height[index];
			int temp_high_index = index;
			bool flag = false;
			while (index < height.size() - 1){
				if (height[index + 1] >= height[start]){
					total_sum += cout_cont(height, start, index + 1);
					i = index + 2;
					start = index + 1;
					flag = true;
					break;
				}
				index++;
				if (height[index] > temp_high) { temp_high = height[index]; temp_high_index = index; }
			}
			if (!flag){
				if (temp_high_index == height.size() - 1){
					total_sum += cout_cont(height, start, temp_high_index);
					return total_sum;
				}
				else{
					total_sum += cout_cont(height, start, temp_high_index);
					i = temp_high_index + 1;
					start = temp_high_index;
				}
			}
		}
		return total_sum;
	}
	int cout_cont(vector<int>& height, int start, int end){
		if (start + 1 == end) return 0;
		int sum = 0;
		int lower = min(height[start], height[end]);
		for (int i = end - 1; i > start; i--){
			if (lower - height[i] > 0) sum += (lower - height[i]);
			else return sum;
		}
		return sum;
	}
};
