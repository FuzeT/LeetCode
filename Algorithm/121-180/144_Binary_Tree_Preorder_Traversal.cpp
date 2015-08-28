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
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> output;
		if (root == NULL) return output;
		stack<TreeNode*> to_browse;
		to_browse.push(root);
		while (!to_browse.empty()){
			TreeNode* this_point = to_browse.top();
			to_browse.pop();
			output.push_back(this_point->val);
			if (this_point->right) to_browse.push(this_point->right);
			if (this_point->left) to_browse.push(this_point->left);
		}
		return output;
	}
};