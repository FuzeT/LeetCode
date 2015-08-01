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

class WordDictionary {
public:
	WordDictionary(){
		root = new trieNode(' ');
	}
	// Adds a word into the data structure.
	void addWord(string word) {
		if (word.size() == 0) return;
		trieNode* temp = root;
		for (int i = 0; i < word.size(); i++){
			bool find = false;
			for (int j = 0; j < temp->next.size(); j++){
				if (temp->next[j]->val == word[i]){ temp = temp->next[j]; find = true; break; }
			}
			if (!find){
				trieNode* newNode = new trieNode(word[i]);
				temp->next.push_back(newNode);
				temp = newNode;
			}
		}
		temp->isWord = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		queue<trieNode*> to_browse;
		to_browse.push(root);
		for (int i = 0; i < word.size(); i++){
			if (to_browse.empty()) return false;
			if (word[i] == '.'){
				queue<trieNode*> temp;
				while (!to_browse.empty()){
					trieNode* thisNode = to_browse.front();
					to_browse.pop();
					for (int j = 0; j < thisNode->next.size(); j++){ temp.push(thisNode->next[j]); }
				}
				to_browse = temp;
			}
			else{
				queue<trieNode*> temp;
				while (!to_browse.empty()){
					trieNode* thisNode = to_browse.front();
					to_browse.pop();
					for (int j = 0; j < thisNode->next.size(); j++){
						if (thisNode->next[j]->val == word[i]) temp.push(thisNode->next[j]);
					}
				}
				to_browse = temp;
			}
		}
		if (to_browse.empty()) return false;
		else{
			while (!to_browse.empty()){
				trieNode* thisNode = to_browse.front();
				to_browse.pop();
				if (thisNode->isWord) return true;
			}
		}
		return false;
	}
private:
	struct trieNode{
		char val;
		vector<trieNode*> next;
		bool isWord;
		trieNode(char c) :val(c), isWord(false){};
	};
	trieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");