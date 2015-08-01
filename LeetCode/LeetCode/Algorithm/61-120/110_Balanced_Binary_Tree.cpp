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
	bool isBalanced(TreeNode* root) {
		ReturnPair output = getRootLength(root);
		return output.balance;
	}

	ReturnPair getRootLength(TreeNode* root){
		if (root == NULL) return ReturnPair(0);
		if (root->left == NULL && root->right == NULL) return ReturnPair(1);
		else{
			ReturnPair try_left = getRootLength(root->left);
			ReturnPair try_right = getRootLength(root->right);
			if (try_left.balance && try_right.balance){
				if (abs(try_left.depth - try_right.depth) <= 1){
					return ReturnPair(max(try_left.depth, try_right.depth) + 1);
				}
				else return ReturnPair(false);
			}
			else return ReturnPair(false);
		}
	}
};
