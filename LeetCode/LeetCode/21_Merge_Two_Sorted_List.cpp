#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;
		else if (l1 == NULL && l2 == NULL)return NULL;
		ListNode* output = new ListNode(0);
		ListNode* pointer = output;
		while (l1 != NULL &&l2 != NULL){
			pointer->next = new ListNode(0);
			if (l1->val > l2->val){
				pointer->val = l2->val;
				l2 = l2->next;
			}
			else{
				pointer->val = l1->val;
				l1 = l1->next;
			}
			pointer = pointer->next;
		}
		while (l1 != NULL){
			pointer->val = l1->val;
			if (l1->next != NULL){ pointer->next = new ListNode(0); pointer = pointer->next; }
			l1 = l1->next;
		}
		while (l2 != NULL){
			pointer->val = l2->val;
			if (l2->next != NULL){ pointer->next = new ListNode(0); pointer = pointer->next; }
			l2 = l2->next;
		}
		return output;
	}
};