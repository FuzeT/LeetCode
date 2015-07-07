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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> output;
		if (root == NULL) return output;
		recursive_method(output, root);
		return output;
	}

	void recursive_method(vector<int>& output, TreeNode* root){
		if (root->left != NULL) recursive_method(output, root->left);
		output.push_back(root->val);
		if (root->right != NULL) recursive_method(output, root->right);
	}
};