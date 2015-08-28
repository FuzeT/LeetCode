/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        bool flag = false;
        while(l1!=NULL && l2!=NULL){
            if (flag){
                temp->val = (l1->val+l2->val+1)%10;
                if((l1->val+l2->val+1)/10){flag = true;}
                else{flag = false;}
                l1 = l1->next;
                l2 = l2->next;
                if(l1!=NULL && l2!=NULL){
                    temp->next = new ListNode(0);
                    temp = temp->next;
                }
            }else{
                temp->val = (l1->val+l2->val)%10;
                if((l1->val+l2->val)/10){flag = true;}
                else{flag = false;}
                l1 = l1->next;
                l2 = l2->next;
                if(l1!=NULL && l2!=NULL){
                    temp->next = new ListNode(0);
                    temp = temp->next;
                }
            }
        }
        while(l1!=NULL){
            temp->next = new ListNode(0);
            temp = temp->next;
            if(flag){
                temp->val = (l1->val+1)%10;
                if((l1->val+1)/10){flag = true;}
                else{flag = false;}
                l1 = l1->next;

            }else{
                temp->val = (l1->val)%10;
                l1 = l1->next;
            }
        }
        while(l2!=NULL){
            temp->next = new ListNode(0);
            temp = temp->next;
            if(flag){
                temp->val = (l2->val+1)%10;
                if((l2->val+1)/10){flag = true;}
                else{flag = false;}
                l2 = l2->next;
            }else{
                temp->val = (l2->val)%10;
                l2 = l2->next;
            }
        }
        if(flag){temp->next = new ListNode(1);}
        return head;
    }
};
