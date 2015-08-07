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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) return NULL;
		return recurse(inorder, postorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* recurse(vector<int>& inorder, vector<int>& postorder, int post_left, int post_right, int in_left, int in_right){
		if (post_left>post_right || in_left>in_right) return NULL;
		TreeNode* head = new TreeNode(postorder[post_right]);
		if (post_left == post_right) return head;
		int i = in_left;
		for (; i <= in_right; i++){
			if (inorder[i] == postorder[post_right]) break;
		}
		head->left = recurse(inorder, postorder, post_left, post_left + i - in_left - 1, in_left, i - 1);
		head->right = recurse(inorder, postorder, post_left + i - in_left, post_right - 1, i + 1, in_right);
		return head;
	}
};
