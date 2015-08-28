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

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 1) return new TreeNode(nums[0]);
		if (nums.size() == 0) return NULL;
		int mid = nums.size() >> 1;
		TreeNode* this_root = new TreeNode(nums[mid]);
		vector<int> left_nums = nums;
		vector<int> right_nums = nums;
		left_nums.erase(left_nums.begin() + mid, left_nums.end());
		right_nums.erase(right_nums.begin(), right_nums.begin() + mid + 1);
		this_root->left = sortedArrayToBST(left_nums);
		this_root->right = sortedArrayToBST(right_nums);
		return this_root;
	}
};