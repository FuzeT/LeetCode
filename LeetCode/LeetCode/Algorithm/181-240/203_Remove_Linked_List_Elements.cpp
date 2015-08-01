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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL) return head;
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		ListNode* pointer = newHead;
		while (pointer->next){
			if (pointer->next->val == val){
				ListNode* temp = pointer->next;
				pointer->next = temp->next;
				delete(temp);
			}
			else{ pointer = pointer->next; }
		}
		return newHead->next;
	}
};