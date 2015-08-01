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

class LRUCache{
public:
	LRUCache(int capacity) {
		max_volumn = capacity;
		head = new order(0, 0);
		tail = new order(0, 0);
	}

	int get(int key) {
		if (stored.find(key) != stored.end()){
			order* temp = stored[key];
			change_to_head(temp);
			return temp->o_value;
		}
		else return -1;
	}

	void set(int key, int value) {
		if (stored.find(key) != stored.end()){
			order* temp = stored[key];
			temp->o_value = value;
			change_to_head(temp);
		}
		else{
			if (stored.size() < max_volumn){
				order* newNode = new order(key, value);
				stored[key] = newNode;
				if (head->next){
					newNode->next = head->next;
					head->next->prior = newNode;
					head->next = newNode;
					newNode->prior = head;
				}
				else{
					tail = newNode;
					head->next = newNode;
					newNode->prior = head;
				}
			}
			else{
				order* newNode = new order(key, value);
				order* temp = tail;
				tail = tail->prior;
				tail->next = NULL;
				stored.erase(temp->o_key);
				delete(temp);
				stored[key] = newNode;
				if (head->next) head->next->prior = newNode;
				else tail = newNode;
				newNode->next = head->next;
				newNode->prior = head;
				head->next = newNode;
			}
		}
	}
private:
	struct order{
		int o_key;
		int o_value;
		order* next;
		order* prior;
		order(int _key, int _value) :o_key(_key), o_value(_value), next(NULL), prior(NULL){};
	};
	unordered_map<int, order*> stored;
	order* head;
	order* tail;
	int max_volumn;

	void change_to_head(order* thisNode){
		if (thisNode->prior == head) return;
		if (thisNode->next == NULL) {
			tail = thisNode->prior; tail->next = NULL;
			thisNode->next = head->next;
			head->next->prior = thisNode;
			thisNode->prior = head;
			head->next = thisNode;
		}
		else{
			if (thisNode->next) thisNode->next->prior = thisNode->prior;
			thisNode->prior->next = thisNode->next;
			thisNode->next = head->next;
			head->next->prior = thisNode;
			thisNode->prior = head;
			head->next = thisNode;
		}
	}
};