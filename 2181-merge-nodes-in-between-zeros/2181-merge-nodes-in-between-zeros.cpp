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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-111);
        ListNode* ptr = dummy;
        head=head->next;
        int val = 0;
        while(head!=NULL){
            if(head->val==0){
                ListNode* temp = new ListNode(val);
                ptr->next = temp;
                ptr = ptr->next;
                val = 0;
            }
            val+=head->val;
            head=head->next;
        }
        return dummy->next;
    }
};