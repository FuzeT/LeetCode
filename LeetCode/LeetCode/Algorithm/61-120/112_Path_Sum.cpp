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
	bool hasPathSum(TreeNode* root, long long sum) {
		if (root == NULL) return false;
		if (root->left == NULL && root->right == NULL && root->val == sum) return true;
		long long new_sum = sum - root->val;
		return(hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum));
	}
};