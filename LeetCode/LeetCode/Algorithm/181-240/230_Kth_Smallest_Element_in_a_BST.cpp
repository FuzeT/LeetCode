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
	int kthSmallest(TreeNode* root, int k) {
		if (root->left == NULL&&root->right == NULL) return root->val;
		auto transToList = trans(root);
		ListNode* temp = transToList->head;
		for (int i = 1; i < k; i++){ temp = temp->next; }
		return temp->val;
	}
private:
	struct ListNode{
		int val;
		ListNode* next;
		ListNode(int x) :val(x), next(NULL){};
	};
	struct ReturnPair{
		ListNode* head;
		ListNode* end;
		ReturnPair(ListNode* a, ListNode* b) :head(a), end(b){};
	};
	ReturnPair* trans(TreeNode* node){
		ListNode* thisNode = new ListNode(node->val);
		if (node->left == NULL&&node->right == NULL) return new ReturnPair(thisNode, thisNode);
		ReturnPair* getLeft, *getRight;
		ListNode* newHead = thisNode;
		ListNode* newEnd = thisNode;
		if (node->left){ getLeft = trans(node->left); newHead = getLeft->head; getLeft->end->next = thisNode; }
		if (node->right){ getRight = trans(node->right); newEnd = getRight->end; thisNode->next = getRight->head; }
		return new ReturnPair(newHead, newEnd);
	}
};