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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		return divide(head);
	}

	ListNode* divide(ListNode* head){
		if (head == NULL || head->next == NULL) return head;
		ListNode* fast = head->next, *slow = head;
		while (fast&&fast->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* head_right = slow->next;
		slow->next = NULL;
		return combine(divide(head), divide(head_right));
	}

	ListNode* combine(ListNode* left, ListNode* right){
		ListNode* newHead = new ListNode(0);
		ListNode* temp = newHead;
		while (left || right){
			if (left && (!right || right->val >= left->val)){
				temp->next = left;
				temp = temp->next;
				left = left->next;
			}
			if (right && (!left || left->val >= right->val)){
				temp->next = right;
				temp = temp->next;
				right = right->next;
			}
		}
		temp->next = NULL;
		return newHead->next;
	}
};