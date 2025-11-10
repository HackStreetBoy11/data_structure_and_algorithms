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
    void fun_count(TreeNode* root,int maxi,int &count)
    {
        if(root==nullptr)return ;
        if(root->val>=maxi)
        {
            count++;
            maxi=root->val;
        }
         fun_count(root->left,maxi,count);
         fun_count(root->right,maxi,count);

    }
    int goodNodes(TreeNode* root) {
        // intution aaayi ki brances mai maximum comparison karna hai
        int maxi = root->val;
        int count=0;
         fun_count(root,maxi,count);
         return count;
    }
};
