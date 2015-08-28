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
		auto back = head;
		while (back != NULL && back->next != NULL){
			auto front = back->next;
			while (front != NULL&&front->val == back->val){
				front = front->next;
			}
			if (front == NULL){
				back->next = NULL;
				return head;
			}
			else{
				back->next = front;
				back = back->next;
			}
		}
		return head;
	}
};