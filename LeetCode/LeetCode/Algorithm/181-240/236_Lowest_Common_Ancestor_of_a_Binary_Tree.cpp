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
		if (root == NULL || p == NULL || q == NULL) return NULL;
		vector<TreeNode*> temp;
		vector<TreeNode*> about_p, about_q;
		getTrace(about_p, about_q, temp, root, p, q);
		int i = 0;
		for (; i<min(about_p.size(), about_q.size()); i++){ if (about_p[i] != about_q[i]) break; }
		return about_p[i - 1];
	}

	void getTrace(vector<TreeNode*>& about_p, vector<TreeNode*>& about_q, vector<TreeNode*>& already, TreeNode* node, TreeNode* p, TreeNode* q){
		if (about_p.size() != 0 && about_q.size() != 0) return;
		if (node == NULL) return;
		already.push_back(node);
		if (node == p) about_p = already;
		if (node == q) about_q = already;
		getTrace(about_p, about_q, already, node->left, p, q);
		getTrace(about_p, about_q, already, node->right, p, q);
		already.pop_back();
	}
};