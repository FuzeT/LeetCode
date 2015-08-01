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


class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		int count = 0;
		auto temp = head;
		while (temp != NULL){ temp = temp->next; count++; }
		return get_next_root(head, count);
	}

	TreeNode* get_next_root(ListNode* head, int ListSize){
		if (ListSize == 0) return NULL;
		else if (ListSize == 1) return new TreeNode(head->val);
		else{
			ListNode* temp = head;
			int mid = ListSize >> 1;
			for (int i = 0; i < mid; i++){ temp = temp->next; }
			TreeNode* this_root = new TreeNode(temp->val);
			this_root->left = get_next_root(head, mid);
			this_root->right = get_next_root(temp->next, ListSize - mid - 1);
			return this_root;
		}
	}
};
