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

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 0 || prerequisites.size() == 0) return true;
		unordered_map<int, graphNode*> dict;
		for (auto iter = prerequisites.begin(); iter != prerequisites.end(); iter++){
			graphNode* front, *back;
			if (dict.find(iter->first) != dict.end()){ back = dict[iter->first]; }
			else{ back = new graphNode(iter->first); dict[iter->first] = back; }
			if (dict.find(iter->second) != dict.end()){ front = dict[iter->second]; }
			else{ front = new graphNode(iter->second); dict[iter->second] = front; }
			back->inter += 1;
			front->next.push_back(back);
		}
		queue<graphNode*> AsHead;
		for (auto iter = dict.begin(); iter != dict.end(); iter++){
			if (iter->second->inter == 0) AsHead.push(iter->second);
		}
		while (!dict.empty()){
			if (AsHead.empty()) return false;
			graphNode* thisNode = AsHead.front();
			AsHead.pop();
			for (auto i = thisNode->next.begin(); i != thisNode->next.end(); i++){
				(*i)->inter -= 1;
				if ((*i)->inter == 0) AsHead.push(*i);
			}
			dict.erase(thisNode->val);
		}
		return true;
	}
private:
	struct graphNode{
		int val;
		int inter;
		vector<graphNode*> next;
		graphNode(int x) :val(x), inter(0){};
	};
};