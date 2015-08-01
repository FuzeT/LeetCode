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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		else return isMirror(root->left, root->right);
	}

	bool isMirror(TreeNode* left, TreeNode* right){
		if (left == NULL || right == NULL) return left == right;
		else{
			if (left->val == right->val) return isMirror(left->left, right->right) && isMirror(left->right, right->left);
			else return false;
		}
	}
};