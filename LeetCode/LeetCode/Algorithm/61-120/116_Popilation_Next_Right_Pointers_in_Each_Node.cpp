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
	TreeNode* start;
	TreeNode* end;
	ReturnPair(TreeNode* x, TreeNode* y) : start(x), end(y){}
};


class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		TreeLinkNode* pointer = root;
		TreeLinkNode* next_level = pointer->left;
		while (pointer->left != NULL){
			pointer->left->next = pointer->right;
			if (pointer->next != NULL){
				pointer->right->next = pointer->next->left;
				pointer = pointer->next;
			}
			else{
				pointer = next_level;
				next_level = pointer->left;
			}
		}
	}
};