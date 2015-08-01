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
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL) return;
		ListNode* first = head, *second = head;
		//find the middle node
		while (first != NULL&&first->next != NULL){
			first = first->next->next;
			second = second->next;
		}
		//reverse the left nodes
		first = second->next;
		second->next = NULL;
		while (first != NULL){
			ListNode* temp = first->next;
			first->next = second;
			second = first;
			first = temp;
		}
		first = head;
		while (1){
			if (second == NULL) break;
			if (first == second) break;
			if (first->next == second) break;
			ListNode* first_temp = first->next, *second_temp = second->next;
			first->next = second;
			second->next = first_temp;
			first = first_temp;
			second = second_temp;
		}
	}
};