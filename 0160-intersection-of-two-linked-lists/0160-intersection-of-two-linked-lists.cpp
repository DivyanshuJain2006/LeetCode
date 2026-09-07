/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        int lenA = 0;
        while(tempA){
            lenA++;
            tempA=tempA->next;
        }
        ListNode* tempB = headB;
        int lenB = 0;
        while(tempB){
            lenB++;
            tempB=tempB->next;
        }
        if(lenA>lenB){
            int diff = lenA-lenB;
            for(int i=1;i<=diff;i++){
                headA=headA->next;
            }
        }
        else{
            int diff=lenB-lenA;
            for(int i=1;i<=diff;i++){
                headB=headB->next;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};