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
    ListNode* add(int val,ListNode* head)
    {
        if(head==NULL)
        {
            ListNode* temp=new ListNode(val);
            head=temp;
        }
        else
        {
            ListNode*temp=head;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=new ListNode(val);
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> minh;
        ListNode* current;
        for(int i=0;i<lists.size();i++)
        {
            current=lists[i];
            while(current)
            {
                minh.push(current->val);
                current=current->next;
            }
        }
        while(minh.size()>0)
        {
            current=add(minh.top(),current);
            minh.pop();
        }
        return current;
    }
};