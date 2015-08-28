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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> output;
		if (root == NULL) return output;
		stack<TreeNode*> to_browse;
		to_browse.push(root);
		while (!to_browse.empty()){
			TreeNode* temp = to_browse.top();
			to_browse.pop();
			if (temp->left) to_browse.push(temp->left);
			if (temp->right) to_browse.push(temp->right);
			output.push_back(temp->val);
		}
		reverse(output.begin(), output.end());
		return output;
	}
};