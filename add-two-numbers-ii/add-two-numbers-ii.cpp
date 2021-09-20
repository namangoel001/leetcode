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
    ListNode *reverse(ListNode *head)
    {
        ListNode *current=head;
        ListNode *next1;
        ListNode *pre=NULL;
        while(current)
        {
            next1=current->next;
            current->next=pre;
            pre=current;
            current=next1;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *current1=l1;
        ListNode *current2=l2;
        int count1=0;
        int count2=0;
        int carry=0;
        while(current1)
        {
            count1++;
            current1=current1->next;
        }
         while(current2)
        {
            count2++;
            current2=current2->next;
        }
        current1=l1;
        current2=l2;
        bool flag=0;
        if(count1>=count2)
            flag=1;
        else
            flag=0;
        if(flag==1)
        {
            while(count1>count2)
            {
                current1=current1->next;
                count1--;
            }
            while(count1>0)
            {
                current1->val=current1->val+current2->val;
                current1=current1->next;
                current2=current2->next;
                count1--;
            }
        }
        else
        {
            while(count2>count1)
            {
                current2=current2->next;
                count2--;
            }
            while(count2>0)
            {
                current2->val=current1->val+current2->val;
                current1=current1->next;
                current2=current2->next;
                count2--;
            }
        }
        if(flag==1)
        {
            current1=reverse(l1);
            ListNode *ptr=current1;
            ListNode *ans=current1;
            while(current1)
            {
            int num=current1->val+carry;
            current1->val=(num%10);
            carry=num/10;
            ptr=current1;
            current1=current1->next;
            }
            if(carry)
            {
                ptr->next=new ListNode(carry);
            }
            current1=reverse(ans);
            return current1;
        }
        else
        {
            current2=reverse(l2);
            ListNode *ptr=current2;
            ListNode *ans=current2;
            while(current2)
            {
            int num=current2->val + carry;
            current2->val=(num%10);
            carry=num/10;
            ptr=current2;
            current2=current2->next;
            }
            if(carry)
            {
                ptr->next=new ListNode(carry);
            }
            current2=reverse(ans);
            return current2;
        }
    }
};