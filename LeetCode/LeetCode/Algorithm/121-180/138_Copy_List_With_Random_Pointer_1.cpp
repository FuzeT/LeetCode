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

//Considered about circle
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		unordered_map<RandomListNode*, int> dict;
		vector<RandomListNode*> old_nodes;
		vector<RandomListNode*> new_nodes;
		queue<RandomListNode*> to_browse;
		dict[head] = 0;
		to_browse.push(head);
		old_nodes.push_back(head);
		new_nodes.push_back(new RandomListNode(head->label));
		while (!to_browse.empty()){
			RandomListNode* old_node = to_browse.front();
			to_browse.pop();
			int old_index = findNodeIndex(dict, old_node);
			RandomListNode* new_node = new_nodes[old_index];
			int old_next_index = findNodeIndex(dict, old_node->next);
			int old_random_index = findNodeIndex(dict, old_node->random);
			if (old_next_index == -1){
				to_browse.push(old_node->next);
				dict[old_node->next] = old_nodes.size();
				old_nodes.push_back(old_node->next);
				RandomListNode* new_next = new RandomListNode(old_node->next->label);
				new_nodes.push_back(new_next);
				new_node->next = new_next;
			}
			else if (old_next_index == -2){
				new_node->next = NULL;
			}
			else{
				new_node->next = new_nodes[old_next_index];
			}
			if (old_random_index == -1){
				to_browse.push(old_node->random);
				dict[old_node->random] = old_nodes.size();
				old_nodes.push_back(old_node->random);
				RandomListNode* new_random = new RandomListNode(old_node->random->label);
				new_nodes.push_back(new_random);
				new_node->next = new_random;
			}
			else if (old_random_index == -2){
				new_node->random = NULL;
			}
			else{
				new_node->random = new_nodes[old_next_index];
			}
		}
		return new_nodes[0];
	}

	int findNodeIndex(unordered_map<RandomListNode*, int> dict, RandomListNode* node){
		if (node == NULL) return -2;
		if (dict.find(node) == dict.end()) return -1;
		return dict[node];
	}
};