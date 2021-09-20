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
    ListNode *reverse(ListNode *head,ListNode *&ptr)
    {
        ptr=head;
        if(!head->next)
            return head;
        ListNode *node=reverse(head->next,ptr);
        node->next=head;
        node=node->next;
        return node;
    }
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next)
           return head;
        ListNode *ptr;
        ListNode *node=reverse(head,ptr);
        node->next=NULL;
        return ptr;
    }
};