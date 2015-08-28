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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* i = head;
		while (i->next != NULL){
			if (i == head){
				ListNode* j = i->next;
				ListNode* temp = j->next;
				j->next = i;
				i->next = temp;
				head = j;
			}
			else{
				ListNode* j = i->next;
				ListNode* temp = j->next;
				if (temp != NULL){
					i->next = temp;
					ListNode* after = temp->next;
					temp->next = j;
					j->next = after;
				}
				i = j;
			}
		}
		return head;
	}
};