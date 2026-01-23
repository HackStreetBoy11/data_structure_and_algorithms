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
// if there is a mid way stopping use boolean beacuse using false or true in mid stops the call'
public:
    bool fun(TreeNode* root, TreeNode* p,vector<TreeNode*> &v)
    {
        if(root==nullptr)return false;
            v.push_back(root);
        if(root==p)
        {
            return true;
        }
        
        if(fun(root->left,p,v) ||fun(root->right,p,v))
        {
            return true;
        }
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        fun(root,p,v1);
        fun(root,q,v2);
        // 3,5,
        // 3,5,2,4
        // ex
        // 3,5
        //3,1
    int i=0;
    int j=0;
    TreeNode* ancestor=nullptr;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]==v2[j])
        {
            ancestor=v1[i];
            i++;
            j++;
        }else{break;}
    }
    return ancestor;
    }
};
