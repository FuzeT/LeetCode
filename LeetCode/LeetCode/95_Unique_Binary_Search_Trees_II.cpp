#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
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
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> output;
		if (n < 1) return vector<TreeNode*>{NULL};
		if (n == 1) return vector<TreeNode*>{new TreeNode(1)};
		map<pair<int, int>, vector<TreeNode*>> dict;
		return recursor(dict, 1, n);
	}

	vector<TreeNode*> recursor(map<pair<int, int>, vector<TreeNode*>>& dict, int start, int end){
		vector<TreeNode*> temp;
		if (start > end) return vector < TreeNode* > {NULL};
		if (dict.find(make_pair(start, end)) != dict.end()) return dict[make_pair(start, end)];
		if (start == end){ dict[make_pair(start, end)] = vector < TreeNode* > {new TreeNode(start)}; return vector < TreeNode* > {new TreeNode(start)}; }
		for (int i = start; i <= end; i++){
			vector<TreeNode*> left = recursor(dict, start, i - 1);
			vector<TreeNode*> right = recursor(dict, i + 1, end);
			for (int in_left = 0; in_left < left.size(); in_left++){
				for (int in_right = 0; in_right < right.size(); in_right++){
					TreeNode* this_tree = new TreeNode(i);
					this_tree->left = left[in_left];
					this_tree->right = right[in_right];
					temp.push_back(this_tree);
				}
			}
		}
		dict[make_pair(start, end)] = temp;
		return temp;
	}
};