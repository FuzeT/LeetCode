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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL || q == NULL) return p == q;
		else{
			if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			else return false;
		}
	}
};