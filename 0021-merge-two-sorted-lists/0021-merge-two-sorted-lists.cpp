/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(-100);
        ListNode* dummy = c;
        while(a!=NULL and b!=NULL){
            if(a->val<=b->val){
                dummy->next=a;
                a=a->next;
            }
            else{
                dummy->next=b;
                b=b->next;
            }
            dummy=dummy->next;
        }
        if(a==NULL) dummy->next=b;
        else dummy->next=a;
        return c->next;
    }
};