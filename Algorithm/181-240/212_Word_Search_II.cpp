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
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> output;
		if (board.size() == 0 || words.size() == 0) return output;
		for (int i = 0; i < words.size(); i++) addWord(words[i]);
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[0].size(); j++){
				string temp;
				Starthear(output, temp, board, i, j, root);
			}
		}
		return output;
	}
private:
	struct trieNode{
		char val;
		bool isWord;
		vector<trieNode*> next;
		trieNode(char c) : val(c), next(26, NULL), isWord(false){};
	};

	trieNode* root = new trieNode(' ');

	void addWord(string word){
		trieNode* temp = root;
		for (int i = 0; i < word.size(); i++){
			if (temp->next[word[i] - 'a'] == NULL){
				temp->next[word[i] - 'a'] = new trieNode(word[i]);
				temp = temp->next[word[i] - 'a'];
			}
			else{
				temp = temp->next[word[i] - 'a'];
			}
		}
		temp->isWord = true;
	}

	void Starthear(vector<string>& output, string already, vector<vector<char>>& board, int row, int col, trieNode* thisNode){
		if (thisNode == NULL || board[row][col] == ' ' || thisNode->next[board[row][col] - 'a'] == NULL) return;
		else{
			if (thisNode->next[board[row][col] - 'a']->isWord) {
				thisNode->next[board[row][col] - 'a']->isWord = false;
				bool check_left = false;
				for (int i = 0; i < 26; i++){
					if ((thisNode->next[board[row][col] - 'a']->next[i]) != NULL) {
						check_left = true;
						break;
					}
				}
				if (!check_left) {
					delete(thisNode->next[board[row][col] - 'a']);
					thisNode->next[board[row][col] - 'a'] = NULL;
				}
				output.push_back(already + board[row][col]);
			}
			char temp = board[row][col];
			board[row][col] = ' ';
			if (row != 0) Starthear(output, already + temp, board, row - 1, col, thisNode->next[temp - 'a']);
			if (col != 0) Starthear(output, already + temp, board, row, col - 1, thisNode->next[temp - 'a']);
			if (row != board.size() - 1) Starthear(output, already + temp, board, row + 1, col, thisNode->next[temp - 'a']);
			if (col != board[0].size() - 1) Starthear(output, already + temp, board, row, col + 1, thisNode->next[temp - 'a']);
			board[row][col] = temp;
		}
	}
};