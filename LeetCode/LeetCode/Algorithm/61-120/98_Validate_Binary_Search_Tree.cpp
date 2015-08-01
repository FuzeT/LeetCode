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


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		long long left_value = INT_MIN, right_value = INT_MAX;
		left_value -= 1;
		right_value += 1;
		return check_by_recurse(root, left_value, right_value);
	}

	bool check_by_recurse(TreeNode* root, long long  left_value, long long  right_value){
		if (root == NULL) return true;
		if (root->val < right_value && root->val > left_value){
			return check_by_recurse(root->left, left_value, root->val) && check_by_recurse(root->right, root->val, right_value);
		}
		else return false;
	}
};
