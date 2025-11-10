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
    int fun(TreeNode* root,int &maxi)
    {
    if(root==nullptr)return 0;
       int lc = max(0,fun(root->left,maxi));
       int rc=  max(0,fun(root->right,maxi));
       maxi = max(maxi,lc+rc+root->val);
       return root->val+max(lc,rc);
        
    }
    int maxPathSum(TreeNode* root) {
        // approach maximum depth + check
        int maxi =root->val;
        fun(root,maxi);
        return maxi;
    }
};
