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
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int level = 1;
		int maximum = level;
		find_deeper(maximum, level, root);
		return maximum;
	}

	void find_deeper(int& maximum, int level, TreeNode* root){
		if (level > maximum){ maximum = level; }
		if (root->left) find_deeper(maximum, level + 1, root->left);
		if (root->right) find_deeper(maximum, level + 1, root->right);
	}
};