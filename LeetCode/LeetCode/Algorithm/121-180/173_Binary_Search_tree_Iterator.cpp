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
#include <unordered_set>

using namespace std;


//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		iter = root;
		if (iter != NULL){
			while (iter->left){ to_browse.push(iter); iter = iter->left; }
			to_browse.push(iter);
		}
		iter = new TreeNode(0);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return(iter->right || (!to_browse.empty()));
	}

	/** @return the next smallest number */
	int next() {
		if (iter->right){
			iter = iter->right;
			while (iter->left) { to_browse.push(iter); iter = iter->left; }
			return iter->val;
		}
		else{
			iter = to_browse.top();
			to_browse.pop();
			return iter->val;
		}
	}
private:
	stack<TreeNode*> to_browse;
	TreeNode* iter;
};