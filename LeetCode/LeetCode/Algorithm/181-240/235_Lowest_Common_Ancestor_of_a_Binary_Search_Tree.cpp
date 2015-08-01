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
#include <inttypes.h>
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int left = min(p->val, q->val), right = max(p->val, q->val);
		while (root){
			if (root->val >= left && root->val <= right) return root;
			if (root->val<left) root = root->right;
			if (root->val>right) root = root->left;
		}
		return NULL;
	}
};