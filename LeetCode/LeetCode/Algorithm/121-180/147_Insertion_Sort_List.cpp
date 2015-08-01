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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL) return head;
		ListNode* newHead = new ListNode(INT_MIN);
		newHead->next = head;
		ListNode* pointer = newHead;
		while (pointer->next){
			if (pointer == newHead) { pointer = pointer->next; continue; }
			ListNode* temp = newHead;
			while (temp){
				if (temp == pointer->next){ pointer = pointer->next; break; }
				if (temp->val == pointer->next->val){
					if (temp == pointer) { pointer = pointer->next; break; }
					ListNode* thisNode = pointer->next;
					pointer->next = thisNode->next;
					thisNode->next = temp->next;
					temp->next = thisNode;
					break;
				}
				if (temp->val<pointer->next->val && temp->next->val<pointer->next->val){ temp = temp->next; continue; }
				else if (temp->val<pointer->next->val && temp->next->val>pointer->next->val){
					ListNode* thisNode = pointer->next;
					pointer->next = thisNode->next;
					thisNode->next = temp->next;
					temp->next = thisNode;
					break;
				}
				else{ temp = temp->next; continue; }
			}
		}
		return newHead->next;
	}
};