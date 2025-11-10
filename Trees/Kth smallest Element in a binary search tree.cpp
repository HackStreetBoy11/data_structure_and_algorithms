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
    void fun(TreeNode* root,vector<int> & result)
    {
        if(root==nullptr)return;
        fun(root->left,result);
        result.push_back(root->val);
        fun(root->right,result);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        // intution is apply inorder traversal  ==> Left Root Right
        vector<int> result;
        fun(root,result);
        return result[k-1];
    }
};
