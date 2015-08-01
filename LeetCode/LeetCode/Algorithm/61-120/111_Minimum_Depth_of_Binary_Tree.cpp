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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct ReturnPair{
	int depth;
	bool balance;
	ReturnPair(int x) : depth(x), balance(true){}
	ReturnPair(bool f) : depth(0), balance(f){};
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int left_minidep = minDepth(root->left);
		int right_minidep = minDepth(root->right);
		if (left_minidep == 0) return right_minidep + 1;
		if (right_minidep == 0) return left_minidep + 1;
		return min(left_minidep, right_minidep) + 1;
	}
};
