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
    {  if(list1==nullptr)return list2;
        if(list2==NULL)return list1;
        Node* result;
           if(list1->data<list2->data)
           {
               result = list1;
               result->bottom = merge_two_sorted_list(list1->bottom,list2);
           }
           else{
               result= list2;
               result->bottom =  merge_two_sorted_list(list1,list2->bottom);
           }
       return result;
    }
    Node *flatten(Node *root) {
        // code here
        if(root==nullptr)return NULL;
        
        Node* head2 = flatten(root->next);
        return merge_two_sorted_list(root,head2);
    }
};
