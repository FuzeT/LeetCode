#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		return recurse(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
	}

	TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right){
		if (pre_left>pre_right || in_left>in_right) return NULL;
		TreeNode* head = new TreeNode(preorder[pre_left]);
		if (pre_left == pre_right) return head;
		int i = in_left;
		for (; i <= in_right; i++){
			if (inorder[i] == preorder[pre_left]) break;
		}
		head->left = recurse(preorder, inorder, pre_left + 1, pre_left + i - in_left, in_left, i - 1);
		head->right = recurse(preorder, inorder, pre_left + i - in_left + 1, pre_right, i + 1, in_right);
		return head;
	}
};
