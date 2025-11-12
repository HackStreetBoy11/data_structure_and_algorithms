/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
     Node* merge_two_sorted_list(Node* list1, Node* list2)
    {  
        if(!list1) return list2;
        if(!list2) return list1;
       
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
        Node* a = list1;
        Node* b = list2;
        
        while(a && b)
        {
            if(a->data < b->data)
            {
                curr->bottom = a;
                a = a->bottom;
            }
            else
            {
                curr->bottom = b;
                b = b->bottom;
            }
            curr = curr->bottom;  // ✅ move pointer correctly
        }
        
        // attach remaining nodes
        if(a) curr->bottom = a;
        else curr->bottom = b;
        
        return dummy->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(root==nullptr)return NULL;
        
        Node* head2 = flatten(root->next);
        return merge_two_sorted_list(root,head2);
    }
};
