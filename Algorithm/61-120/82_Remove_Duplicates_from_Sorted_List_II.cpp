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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		while (head->next != NULL && head->next->val == head->val){
			int duplicate = head->val;
			while (head->next != NULL && head->next->val == duplicate){
				auto temp = head->next;
				delete(head);
				head = temp;
			}
			if (head->next == NULL) return NULL;
			else {
				auto temp = head->next;
				delete(head);
				head = temp;
			}
		}
		if (head == NULL || head->next == NULL) return head;
		auto back = head;
		while (back != NULL && back->next != NULL){
			auto front = back->next;
			if (front->next == NULL){
				back = back->next;
			}
			else if (front->next->val != front->val){
				back = back->next;
			}
			else{
				auto temp = find_next_head(front);
				back->next = temp;
				back = temp;
			}
		}
		return head;
	}

	ListNode* find_next_head(ListNode* head){
		while (head != NULL && head->next != NULL && head->next->val == head->val){
			int duplicate = head->val;
			while (head->next != NULL && head->next->val == duplicate){
				auto temp = head->next;
				delete(head);
				head = temp;
			}
			if (head->next == NULL) head = NULL;
			else {
				auto temp = head->next;
				delete(head);
				head = temp;
			}
		}
		return head;
	}
};