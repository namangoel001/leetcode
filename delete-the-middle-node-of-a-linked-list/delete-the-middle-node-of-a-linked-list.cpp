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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;
        int count=0;
        ListNode *current=head;
        while(current)
        {
         count++;
         current=current->next;
        }
        count/=2;
        current=head;
        for(int i=0;i<count-1;i++){
            current=current->next;
        }
        ListNode *temp=current->next;
        current->next=temp->next;
        delete(temp);
        return head;
    }
};