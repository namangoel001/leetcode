/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *make_bt(int &post_idx,vector<int> &postorder,unordered_map<int,int> &mp,int start,int end)
    {
        if(start>end)
            return NULL;
        int current=postorder[post_idx];
        post_idx--;
        TreeNode *root=new TreeNode(current);
        int pos=mp[current];
        root->right=make_bt(post_idx,postorder,mp,pos+1,end);
        root->left=make_bt(post_idx,postorder,mp,start,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        int n=postorder.size();
        int post_idx=n-1;
        return make_bt(post_idx,postorder,mp,0,n-1);
    }
};