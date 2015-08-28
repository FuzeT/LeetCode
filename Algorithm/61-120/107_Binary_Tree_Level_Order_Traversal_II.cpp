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

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> output;
		if (root == NULL) return output;
		queue<pair<TreeNode*, int>> temp;
		temp.push(make_pair(root, 1));
		while (!temp.empty()){
			vector<int> temp_output;
			pair<TreeNode*, int> head = temp.front();
			int level = head.second;
			while (head.second == level){
				if (head.first->left) temp.push(make_pair(head.first->left, level + 1));
				if (head.first->right) temp.push(make_pair(head.first->right, level + 1));
				temp_output.push_back(head.first->val);
				temp.pop();
				if (temp.empty()) break;
				head = temp.front();
			}
			output.push_back(temp_output);
		}
		reverse(output.begin(), output.end());
		return output;
	}
};