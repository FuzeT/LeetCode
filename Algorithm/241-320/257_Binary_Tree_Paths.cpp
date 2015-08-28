#include <iostream>
#include <string>
#include <strstream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> output;
		if (root == NULL) return output;
		string start = Int_String(root->val);
		if(root->left) recurse(root->left, start, output);
		if (root->right) recurse(root->right, start, output);
		if (root->left == NULL && root->right == NULL) output.push_back(start);
		return output;
	}

	void recurse(TreeNode* root, string& temp_output, vector<string>& output) {
		string temp = Int_String(root->val);
		temp = temp_output + "->" + temp;
		if (root->left) recurse(root->left, temp, output);
		if (root->right) recurse(root->right, temp, output);
		if (root->left == NULL && root->right == NULL) output.push_back(temp);
	}

	string Int_String(int n) {
		long long temp = n;
		bool flag = true;
		string output;
		if (temp < 0) { temp *= -1; flag = false; }
		while (temp) {
			output = char('0' + temp % 10) + output;
			temp /= 10;
		}
		return flag ? output : ('-' + output);
	}
};
