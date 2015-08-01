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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		int lengthA = 0, lengthB = 0;
		ListNode* temp = headA;
		while (temp){ temp = temp->next; lengthA++; }
		temp = headB;
		while (temp){ temp = temp->next; lengthB++; }
		while (lengthA != lengthB){
			if (lengthA>lengthB) { headA = headA->next; lengthA--; }
			if (lengthA<lengthB) { headB = headB->next; lengthB--; }
		}
		while (headA&&headB){
			if (headA == headB) return headA;
			else{ headA = headA->next; headB = headB->next; }
		}
		return NULL;
	}
};