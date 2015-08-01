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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LRUCache{
public:
	LRUCache(int capacity) {
		max_contain = capacity;
		already_contain = 0;
		head = new innerPair(0, 0);
	}

	int get(int key) {
		innerPair* temp = head->next;
		while (temp){
			if (temp->s_key == key){
				if (temp->prior == head) return temp->s_value;
				temp->prior->next = temp->next;
				if (temp->next) temp->next->prior = temp->prior;
				head->next->prior = temp;
				temp->next = head->next;
				temp->prior = head;
				head->next = temp;
				return temp->s_value;
			}
			temp = temp->next;
		}
		return -1;
	}

	void set(int key, int value) {
		innerPair* temp = head->next;
		innerPair* last = temp;
		while (temp){
			if (temp->s_key == key) break;
			else {
				if (temp->next) temp = temp->next;
				else{ last = temp; temp = temp->next; }
			}
		}
		if (temp != NULL){
			temp->s_value = value;
			if (temp == head->next) return;
			temp->prior->next = temp->next;
			if (temp->next) temp->next->prior = temp->prior;
			head->next->prior = temp;
			temp->next = head->next;
			temp->prior = head;
			head->next = temp;
			return;
		}
		else{
			if (already_contain < max_contain){
				already_contain++;
				innerPair* new_input = new innerPair(key, value);
				if (head->next){ head->next->prior = new_input; }
				new_input->next = head->next;
				new_input->prior = head;
				head->next = new_input;
			}
			else{
				last->s_key = key;
				last->s_value = value;
				if (last == head->next) return;
				last->prior->next = NULL;
				last->next = head->next;
				head->next->prior = last;
				head->next = last;
				last->prior = head;
			}
		}
	}
private:

	struct innerPair{
		int s_key;
		int s_value;
		innerPair* prior;
		innerPair* next;
		innerPair(int _key, int _value) :s_key(_key), s_value(_value), prior(NULL), next(NULL){};
	};
	innerPair* head;
	int max_contain;
	int already_contain;
};