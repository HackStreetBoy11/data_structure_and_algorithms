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
    void fun(vector<int>&temp,TreeNode* root)
    {
        if(root==NULL )return;
        fun(temp,root->left);
        temp.push_back(root->val);
        fun(temp,root->right);
    }
    TreeNode* create_bst(vector<int>&temp,int l,int r)
    {
        if(l>r)return NULL;
            int mid = l+(r-l)/2;
            TreeNode* node = new TreeNode(temp[mid]);
            node->left = create_bst(temp,l,mid-1);
            node->right = create_bst(temp,mid+1,r);
            return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // inorder traversal
        vector<int>temp;
        fun(temp,root);
        return create_bst(temp,0,temp.size()-1);
    }
};
