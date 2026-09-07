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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }
        int ans = 0 ;
        int i = size-1;
        temp = head;
        while(temp!=NULL){
            ans = ans + temp->val*pow(2,i);
            temp = temp->next;
            i--;
        }
        return ans;
    }
};