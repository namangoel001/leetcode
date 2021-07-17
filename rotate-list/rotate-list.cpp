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
        if(!head)
            return NULL;
        int count=0;
        ListNode* current=head;
        while(current->next)
        {
            current=current->next;
            count++;
        }
        current->next=head;
        count++;
        k=k%count;
        for(int i=1;i<count-k;i++)
        {
            head=head->next;
        }
        current=head->next;
        head->next=NULL;
        return current;
    }
};