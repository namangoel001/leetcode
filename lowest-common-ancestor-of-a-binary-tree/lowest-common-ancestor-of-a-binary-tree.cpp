/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root,TreeNode *p,TreeNode *q)
    {
        if(!root)
            return 0;
        if(root==p || root==q)
            return 1;
        return check(root->left,p,q) || check(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root==p || root==q)
            return root;
        bool l=check(root->left,p,q);
        bool r=check(root->right,p,q);
        if(l==1 && r==1)
            return root;
        if(l==1)
            return lowestCommonAncestor(root->left,p,q);
        if(r==1)
            return lowestCommonAncestor(root->right,p,q);
        return NULL;
    }
};