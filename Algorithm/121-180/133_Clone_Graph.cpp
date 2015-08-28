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

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		queue<UndirectedGraphNode*> to_browse;
		to_browse.push(node);
		unordered_map<int, UndirectedGraphNode*> dict;
		while (!to_browse.empty()){
			UndirectedGraphNode* temp = to_browse.front();
			to_browse.pop();
			if (dict.find(temp->label) == dict.end()){
				dict[temp->label] = new UndirectedGraphNode(temp->label);
				UndirectedGraphNode* new_node = dict[temp->label];
				for (auto connect_node = temp->neighbors.begin(); connect_node != temp->neighbors.end(); connect_node++){
					if (dict.find((*connect_node)->label) == dict.end()){
						UndirectedGraphNode* next_node = new UndirectedGraphNode((*connect_node)->label);
						dict[next_node->label] = next_node;
						new_node->neighbors.push_back(next_node);
						to_browse.push(*connect_node);
					}
					else{
						new_node->neighbors.push_back(dict[(*connect_node)->label]);
					}
				}
			}
			else{
				UndirectedGraphNode* new_node = dict[temp->label];
				for (auto connect_node = temp->neighbors.begin(); connect_node != temp->neighbors.end(); connect_node++){
					if (dict.find((*connect_node)->label) == dict.end()){
						UndirectedGraphNode* next_node = new UndirectedGraphNode((*connect_node)->label);
						dict[next_node->label] = next_node;
						new_node->neighbors.push_back(next_node);
						to_browse.push(*connect_node);
					}
					else{
						UndirectedGraphNode* next_node = dict[(*connect_node)->label];
						new_node->neighbors.push_back(next_node);
					}
				}
			}
		}
		return dict[node->label];
	}
};