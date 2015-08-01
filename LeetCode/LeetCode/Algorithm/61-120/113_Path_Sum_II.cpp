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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct ReturnPair{
	int depth;
	bool balance;
	ReturnPair(int x) : depth(x), balance(true){}
	ReturnPair(bool f) : depth(0), balance(f){};
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> output;
		if (root == NULL) return output;
		vector<int> temp_output;
		AddToVector(output, temp_output, root, sum);
		return output;
	}

	void AddToVector(vector<vector<int>>& output, vector<int> already_in, TreeNode* root, long long sum){
		if (root == NULL) return;
		vector<int> new_already_in = already_in;
		new_already_in.push_back(root->val);
		if (root->left == NULL && root->right == NULL && root->val == sum) { output.push_back(new_already_in); }
		AddToVector(output, new_already_in, root->left, sum - root->val);
		AddToVector(output, new_already_in, root->right, sum - root->val);
	}
};