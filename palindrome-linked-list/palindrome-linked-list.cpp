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
    bool check_palindrome(ListNode *head1,ListNode *&head2)
    {
        if(!head1)
            return true;
        bool first=check_palindrome(head1->next,head2);
        bool second=head1->val==head2->val;
        head2=head2->next;
        return first && second;
    }
    bool isPalindrome(ListNode *head1)
    {
      return check_palindrome(head1,head1);
    }
};