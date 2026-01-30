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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        q.push(root);
        if(depth==1)
        {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        int dpt=1;
        while(!q.empty()){
            int n =q.size();
            while(n--)
            {   TreeNode* node = q.front();
                q.pop();
                if(dpt==depth-1) // 2== 3-1 |2 no
                {
                    TreeNode* nodeRight = node->right;
                    TreeNode* nodeLeft = node->left;
                    TreeNode* newNodeLeft = new TreeNode(val);
                    TreeNode* newNodeRight = new TreeNode(val);
                    node->left = newNodeLeft;
                    node->right = newNodeRight;
                    newNodeLeft->left = nodeLeft;
                    newNodeRight->right = nodeRight;
                }
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            dpt++;// 1 se 2 se 3 
            if(dpt==depth)break; // 2==2 haa
        }
        return root;
    }
};
