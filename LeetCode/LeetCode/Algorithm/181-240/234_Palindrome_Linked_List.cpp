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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		ListNode* front = head;
		ListNode* back = head;
		while (front != NULL && front->next != NULL){
			front = front->next->next;
			back = back->next;
		}
		ListNode* newHead = new ListNode(0);
		while (back){
			ListNode* temp = back;
			back = back->next;
			temp->next = newHead->next;
			newHead->next = temp;
		}
		front = head;
		back = newHead->next;
		while (front&&back){
			if (front->val != back->val) return false;
			front = front->next;
			back = back->next;
		}
		return true;
	}
};