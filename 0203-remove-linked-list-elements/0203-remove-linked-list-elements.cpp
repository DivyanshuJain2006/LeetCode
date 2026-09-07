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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyA = new ListNode(-100);
        ListNode* tempA = dummyA;
        while(head){
            if(head->val!=val){
                tempA->next=head;
                tempA=tempA->next;
            }
            head=head->next;
        }
        tempA->next=NULL;
        return dummyA->next;
    }
};