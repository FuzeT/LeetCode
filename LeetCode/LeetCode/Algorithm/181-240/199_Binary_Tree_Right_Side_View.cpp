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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> output;
		if (root == NULL) return output;
		queue<pair<int, TreeNode*>> to_browse;
		to_browse.push(make_pair(1, root));
		int level_now = 0;
		while (!to_browse.empty()){
			int thisLevel = to_browse.front().first;
			TreeNode* thisNode = to_browse.front().second;
			to_browse.pop();
			if (thisLevel > level_now){ output.push_back(thisNode->val); level_now++; };
			if (thisNode->right) to_browse.push(make_pair(thisLevel + 1, thisNode->right));
			if (thisNode->left) to_browse.push(make_pair(thisLevel + 1, thisNode->left));
		}
		return output;
	}
};