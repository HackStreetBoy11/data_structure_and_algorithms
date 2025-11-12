/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root,Node*& prev)
    {
        if(root==nullptr)return ;
        inorder(root->left,prev);
        prev->left =nullptr;
        prev->right=root;
        prev = root;
        inorder(root->right,prev);

    }
    Node *flattenBST(Node *root) {
        // code here
        Node* head= new Node(-1);
        Node* prev = head;
        inorder(root,prev);
        prev->left=nullptr;
        prev->right=nullptr;
        return head->right;
        
    }
};
