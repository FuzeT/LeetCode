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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* start = newhead;
		ListNode* end;
		for (int i = 1; i < m; i++){ start = start->next; }
		end = start->next;
		for (int i = m; i < n; i++){ end = end->next; }
		ListNode* temp = start->next;
		ListNode* next_end = end->next;
		while (temp != end){
			ListNode* next_node = temp->next;
			temp->next = next_end;
			next_end = temp;
			temp = next_node;
		}
		start->next = end;
		end->next = next_end;
		return newhead->next;
	}
};
