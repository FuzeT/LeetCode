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

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		val = ' ';
	}
	TrieNode(char c) {
		val = c;
		asEnd = false;
	}
private:
	friend class Trie;
	bool asEnd;
	char val;
	vector<TrieNode*> next;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* thisNode = root;
		for (int i = 0; i < word.size(); i++){
			bool found = false;
			vector<TrieNode*> nextLevel = thisNode->next;
			for (auto iter = nextLevel.begin(); iter != nextLevel.end(); iter++){
				if ((*iter)->val == word[i]){ thisNode = *iter; found = true; break; }
			}
			if (!found){
				TrieNode* newNode = new TrieNode(word[i]);
				thisNode->next.push_back(newNode);
				thisNode = newNode;
			}
		}
		thisNode->asEnd = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* thisNode = root;
		for (int i = 0; i < word.size(); i++){
			bool found = false;
			vector<TrieNode*> nextLevel = thisNode->next;
			for (auto iter = nextLevel.begin(); iter != nextLevel.end(); iter++){
				if ((*iter)->val == word[i]){ thisNode = *iter; found = true; break; }
			}
			if (!found){
				return false;
			}
		}
		return thisNode->asEnd;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* thisNode = root;
		for (int i = 0; i < prefix.size(); i++){
			bool found = false;
			vector<TrieNode*> nextLevel = thisNode->next;
			for (auto iter = nextLevel.begin(); iter != nextLevel.end(); iter++){
				if ((*iter)->val == prefix[i]){ thisNode = *iter; found = true; break; }
			}
			if (!found){
				return false;
			}
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
