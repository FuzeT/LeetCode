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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct ReturnPair{
	int level;
	TreeLinkNode* node;
	ReturnPair(int x, TreeLinkNode* y) : level(x), node(y){}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		int level = 0;
		TreeLinkNode* pointer = root;
		ReturnPair store_next_level = ReturnPair(0, root);
		while (pointer && (pointer->left || pointer->right || pointer->next || store_next_level.node)){
			ReturnPair new_level = getNextLevel(level, pointer);
			if (new_level.level > store_next_level.level) store_next_level = new_level;
			if (pointer->left&& pointer->right){
				pointer->left->next = pointer->right;
				if (pointer->next){
					pointer->right->next = getNextChild(pointer->next);
					pointer = pointer->next;
				}
				else{
					pointer = store_next_level.node;
					level++;
				}
			}
			else if (pointer->left){
				if (pointer->next){
					pointer->left->next = getNextChild(pointer->next);
					pointer = pointer->next;
				}
				else{
					pointer = store_next_level.node;
					level++;
				}
			}
			else if (pointer->right){
				if (pointer->next){
					pointer->right->next = getNextChild(pointer->next);
					pointer = pointer->next;
				}
				else{
					pointer = store_next_level.node;
					level++;
				}
			}
			else{
				if (pointer->next) pointer = pointer->next;
				else { pointer = store_next_level.node; level++; }
			}
		}
	}

	ReturnPair getNextLevel(int level, TreeLinkNode* root){
		while (root && (root->left || root->right || root->next)){
			if (root->left) return ReturnPair(level + 1, root->left);
			else if (root->right) return ReturnPair(level + 1, root->right);
			else root = root->next;
		}
		return ReturnPair(level + 1, NULL);
	}

	TreeLinkNode* getNextChild(TreeLinkNode* root){
		while (root && (root->left || root->right || root->next)){
			if (root->left) return root->left;
			else if (root->right) return root->right;
			else root = root->next;
		}
		return NULL;
	}
};

