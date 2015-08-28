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
	TreeNode* start;
	TreeNode* end;
	ReturnPair(TreeNode* x, TreeNode* y) : start(x), end(y){}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL) return;
		ReturnPair output = generateNewTree(root);
	}

	ReturnPair generateNewTree(TreeNode* root){
		if (root->left == NULL && root->right == NULL) return ReturnPair(root, root);
		if (root->left != NULL){
			ReturnPair new_left = generateNewTree(root->left);
			root->left = NULL;
			if (root->right != NULL){
				ReturnPair new_right = generateNewTree(root->right);
				root->right = new_left.start;
				new_left.end->right = new_right.start;
				return ReturnPair(root, new_right.end);
			}
			else {
				root->right = new_left.start;
				return ReturnPair(root, new_left.end);
			}
		}
		else{
			ReturnPair new_right = generateNewTree(root->right);
			root->right = new_right.start;
			return ReturnPair(root, new_right.end);
		}
	}
};