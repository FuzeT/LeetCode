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
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		int left_height = getHight(root->left);
		int right_height = getHight(root->right);
		if (left_height == right_height)
			return pow(2, left_height) + countNodes(root->right);
		return pow(2, right_height) + countNodes(root->left);
	}

	int getHight(TreeNode* node) {
		int height = 0;
		while (node) { node = node->left; height++; }
		return height;
	}
};