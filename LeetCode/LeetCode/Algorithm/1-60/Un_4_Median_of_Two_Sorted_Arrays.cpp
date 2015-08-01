#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m == 0 && n == 0) return NULL;
		if ((m + n) % 2 == 1){
			if (m == 0) return nums2[n / 2];
			if (n == 0) return nums1[m / 2];
			int k = (m + n) / 2;
			return getHthMin(nums1, 1, m, nums2, 1, n, k);
		}
		else{
			if (m == 0) return double(nums2[n / 2] + nums2[n / 2 - 1]) / 2;
			if (n == 0) return double(nums1[m / 2] + nums1[m / 2 - 1]) / 2;
			int k_1 = (m + n) / 2 + 1;
			int k_2 = (m + n) / 2;
			auto x = getHthMin(nums1, 1, m, nums2, 1, n, k_1);
			auto y = getHthMin(nums1, 1, m, nums2, 1, n, k_2);
			return double(getHthMin(nums1, 1, m, nums2, 1, n, k_1) + getHthMin(nums1, 1, m, nums2, 1, n, k_2)) / 2;
		}
	}
private:
	int getHthMin(vector<int> a, int start_a, int end_a, vector<int> b, int start_b, int end_b, int h){
		if (h <= 1){ return min(a[start_a - 1], b[start_b - 1]); }
		int size_a = end_a - start_a + 1, size_b = end_b - start_b + 1, i = 0, j = 0;
		if (size_a == 1){ return b[start_b + h - 3]; }
		if (size_b == 1){ return a[start_a + h - 3]; }
		i = (double(size_a) / (size_a + size_b))*h;
		j = (double(size_b) / (size_a + size_b))*h;
		if (a[start_a + i - 1] < b[start_b + j - 1]){ return getHthMin(a, start_a + i, end_a, b, start_b, start_b + j, h - i); }
		else if (a[start_a + i - 1] > b[start_b + j - 1]){ return getHthMin(a, start_a, start_a + i, b, start_b + j, end_b, h - j); }
		else return a[start_a + i - 1];
	}
};