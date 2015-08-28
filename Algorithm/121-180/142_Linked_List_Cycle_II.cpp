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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode* fast = head, *slow = head;
		int flag = 0;
		while (fast != NULL && slow != NULL){
			if (fast == slow && (flag != 0)) break;
			if (slow->next == NULL) return NULL;
			slow = slow->next;
			if (fast == NULL || fast->next == NULL) return NULL;
			fast = fast->next->next;
			flag++;
		}
		if (slow == NULL || fast == NULL) return NULL;
		slow = head;
		while (slow != fast){ slow = slow->next; fast = fast->next; }
		return slow;
	}
};