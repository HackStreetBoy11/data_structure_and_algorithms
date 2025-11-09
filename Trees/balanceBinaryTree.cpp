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
    int fun(TreeNode* root,bool &check)
    {
        if(root==NULL)return 0;

        int lh = fun(root->left,check);
        int rh =fun(root->right,check);
        int diff = abs(lh-rh);
        if(diff>1){
            check=false;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        // if height difference is greater than one return false;
        bool check=true;
       fun(root,check);
        return check;
    }
};
