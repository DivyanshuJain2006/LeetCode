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
    ListNode* partition(ListNode* head, int val) {
        ListNode* dummyA = new ListNode(100);
        ListNode* dummyB = new ListNode(100);
        ListNode* tempA = dummyA;
        ListNode* tempB = dummyB;
        while(head!=NULL){
            if(head->val<val){
                tempA->next=head;
                tempA=tempA->next;
            }
            else{
                tempB->next = head;
                tempB=tempB->next;
        }
            head=head->next;
        }
        tempA->next = dummyB->next;
        tempB->next = NULL;
        return dummyA->next;
    }
};