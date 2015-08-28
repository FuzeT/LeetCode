#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
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
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* new_head = new ListNode(INT_MIN);
		new_head->next = head;
		ListNode* flag = new_head;
		ListNode* pointer = head;
		while (flag->next != NULL&&flag->next->val<x){
			flag = flag->next;
		}
		if (flag->next == NULL) return head;
		pointer = flag->next;
		while (pointer != NULL && pointer->next != NULL){
			if (pointer->next->val >= x){ pointer = pointer->next; }
			else{
				auto temp = pointer->next;
				pointer->next = pointer->next->next;
				temp->next = flag->next;
				flag->next = temp;
				flag = flag->next;
			}
		}
		return new_head->next;
	}
};