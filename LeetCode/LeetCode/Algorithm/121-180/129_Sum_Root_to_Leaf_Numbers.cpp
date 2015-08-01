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

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};


struct return_pair{
	int sum;
	multiset<int> flag;
	return_pair(){  };
	return_pair(int new_sum, int num){
		sum = new_sum;
		flag.insert(num);
	};
	return_pair(int new_sum, multiset<int> new_flag) {
		sum = new_sum;
		flag = new_flag;
	};
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (root == NULL) return 0;
		return_pair* output = get_path_num(root);
		return output->sum;
	}

	return_pair* get_path_num(TreeNode* root){
		if (root->left == NULL && root->right == NULL) return new return_pair(root->val, 1);
		return_pair *left = NULL, *right = NULL;
		if (root->left) left = get_path_num(root->left);
		if (root->right) right = get_path_num(root->right);
		int sum = 0;
		multiset<int> new_flag;
		if (left != NULL){
			sum += left->sum;
			for (auto i = left->flag.begin(); i != left->flag.end(); i++){
				sum += root->val* (*i) * 10;
				new_flag.insert((*i) * 10);
			}
		}
		if (right != NULL){
			sum += right->sum;
			for (auto i = right->flag.begin(); i != right->flag.end(); i++){
				sum += root->val* (*i) * 10;
				new_flag.insert((*i) * 10);
			}
		}
		return new return_pair(sum, new_flag);
	}
};