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

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		RandomListNode* node = head;
		while (node){
			RandomListNode* nextNode = node->next;
			node->next = new RandomListNode(node->label);
			node->next->next = nextNode;
			node = nextNode;
		}
		node = head;
		while (node){
			if (node->random == NULL) node->next->random = NULL;
			else node->next->random = node->random->next;
			node = node->next->next;
		}
		RandomListNode* new_head = new RandomListNode(0), *temp = new_head;
		node = head;
		while (node){
			temp->next = node->next;
			node->next = temp->next->next;
			temp = temp->next;
			node = temp->next;
		}
		return new_head->next;
	}
};