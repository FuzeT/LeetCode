#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		int start_from_tail = m + n - 1;
		int nums1_start = m - 1, nums2_start = n - 1;
		while (start_from_tail >= 0){
			if (nums1_start < 0){ nums1[start_from_tail] = nums2[nums2_start]; start_from_tail--; nums2_start--; continue; }
			if (nums2_start < 0){ nums1[start_from_tail] = nums1[nums1_start]; start_from_tail--; nums1_start--; continue; }
			if (nums1[nums1_start]>nums2[nums2_start]){
				nums1[start_from_tail] = nums1[nums1_start];
				start_from_tail--;
				nums1_start--;
			}
			else{
				nums1[start_from_tail] = nums2[nums2_start];
				start_from_tail--;
				nums2_start--;
			}
		}
	}
};