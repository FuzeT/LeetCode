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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* newHead = new ListNode(0);
		ListNode* temp = head;
		while (temp){
			ListNode* newTemp = temp->next;
			temp->next = newHead->next;
			newHead->next = temp;
			temp = newTemp;
		}
		return newHead->next;
	}
};