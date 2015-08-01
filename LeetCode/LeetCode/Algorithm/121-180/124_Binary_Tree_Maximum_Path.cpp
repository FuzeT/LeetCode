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
	int maxPathSum(TreeNode* root) {
		if (root == NULL) return 0;
		int max_value = INT_MIN;
		reGenerate(root, max_value);
		return max_value;
	}

	int reGenerate(TreeNode* root, int& max_value){
		if (root->left == NULL && root->right == NULL) { max_value = max(max_value, root->val); return root->val; }
		int left_value = 0, right_value = 0, new_value = 0;
		if (root->left)  left_value = reGenerate(root->left, max_value);
		if (root->right) right_value = reGenerate(root->right, max_value);
		max_value = max(max_value, root->val + left_value + right_value);
		max_value = max(max_value, root->val + left_value);
		max_value = max(max_value, root->val + right_value);
		max_value = max(max_value, root->val);
		new_value = max(root->val + left_value, root->val + right_value);
		new_value = max(new_value, root->val);
		root->val = new_value;
		return new_value;
	}
};