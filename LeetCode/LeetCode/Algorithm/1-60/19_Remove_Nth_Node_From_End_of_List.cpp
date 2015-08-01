#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) return NULL;
		ListNode* fronter = head;
		for (int i = 0; i < n; i++){
			if (fronter != NULL) fronter = fronter->next;
			else return NULL;
		}
		if (fronter == NULL){
			ListNode* temp = head;
			head = head->next;
			delete temp;
			return head;
		}
		ListNode* behinder = head;
		while (fronter->next != NULL){
			fronter = fronter->next;
			behinder = behinder->next;
		}
		ListNode* temp = behinder->next;
		behinder->next = temp->next;
		delete temp;
		return head;
	}
};