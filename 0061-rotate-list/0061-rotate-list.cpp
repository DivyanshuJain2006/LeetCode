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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int size = 0;
        ListNode* temp = head;
        ListNode* tail = head;
        while(temp){
            size++;
            if(temp->next==NULL) tail = temp;
            temp = temp->next;
        }
        if(head==NULL || k==0) return head;
        k = k%size;
        temp = head;
        for(int i=1;i<=size-k-1;i++){
            temp = temp->next;
        }
        tail->next=head;
        head = temp->next;
        temp->next=NULL;
        return head;
    }
};