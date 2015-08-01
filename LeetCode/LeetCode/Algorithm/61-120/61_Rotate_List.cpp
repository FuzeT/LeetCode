#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL) return head;
		int length = 1;
		ListNode* pointer = head->next;
		while (pointer != NULL){ length++; pointer = pointer->next; }
		k = k%length;
		if (k == 0) return head;
		ListNode* front = head;
		ListNode* behind = head;
		for (int i = 0; i < k; i++){ front = front->next; }
		while (front->next != NULL){ front = front->next; behind = behind->next; }
		pointer = behind->next;
		front->next = head;
		behind->next = NULL;
		return pointer;
	}
};