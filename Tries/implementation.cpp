class Trie {
public:
    struct Node{
        bool isLeaf;
        Node* children[26];
        Node(){ // constructor will be called when a new root is formed

            isLeaf= false;
            for(int i =0;i<26;i++)
            {
                children[i]=nullptr;
            }
        }
    };
    Node* root; // global pointer  of a object of a class
    
    Trie() {// will be called when a ojbect is created
       root = new Node();
    }
    void insert(string word) {
        Node* curr = root;
        for(char ch:word)
        {
            int idx = ch-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new Node(); // initialize new memory in heap
            }
            curr=curr->children[idx];
        }
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char c:word){
            int idx = c-'a';
            if(curr->children[idx]==nullptr)return false;
            curr=curr->children[idx];
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Node* curr= root;
         for(char c:prefix){
            int idx = c-'a';
            if(curr->children[idx]==nullptr)return false;
            curr=curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
