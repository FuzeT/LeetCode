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
	bool hasCycle(ListNode *head) {
		if (head == NULL) return false;
		ListNode* fast = head, *slow = head;
		int flag = 0;
		while (fast != NULL && slow != NULL){
			if (fast == slow && (flag != 0)) return true;
			if (slow->next == NULL) return false;
			slow = slow->next;
			if (fast == NULL || fast->next == NULL) return false;
			fast = fast->next->next;
			flag++;
		}
		return false;
	}
};