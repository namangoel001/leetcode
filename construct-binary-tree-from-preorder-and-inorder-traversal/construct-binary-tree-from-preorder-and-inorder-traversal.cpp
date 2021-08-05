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
    int search(vector<int> inorder, int current,int start,int end)
    {
        for(int i=0;i<=end;i++)
        {
            if(inorder[i]==current)
                return i;
        }
        return -1;
    }
    TreeNode *make_bt(int &pre_idx,vector<int> preorder, vector<int> inorder,int start,int end)
    {
        if(start>end)
            return NULL;
        int current=preorder[pre_idx];
        TreeNode *root= new TreeNode(current);
        pre_idx++;
        int pos=search(inorder,current,start,end);
        root->left=make_bt(pre_idx,preorder,inorder,start,pos-1);
        root->right=make_bt(pre_idx,preorder,inorder,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // unordered_map<int,int> mp;
        // for(int i=0;i<inorder.size();i++)
        //     mp[inorder[i]]=i;
        int pre_idx=0;
        int n=preorder.size();
        return make_bt(pre_idx,preorder,inorder,0,n-1);
    }
};