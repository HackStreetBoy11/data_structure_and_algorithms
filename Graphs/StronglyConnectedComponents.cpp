//Position this line where user code will be pasted.
class Solution {
  public:
    
    void dfs(stack<int>&sk,vector<bool>& visited,vector<vector<int>>&mp,int node)
    {
        visited[node]=true;
        for(auto &nbr:mp[node])
        {
            if(!visited[nbr])
            {
                dfs(sk,visited,mp,nbr);
            }
            
        }
        sk.push(node);
        return ;
    }
    
    void reverse_dfs(vector<bool> & visited,int node, vector<vector<int>>&mp)
    {   
        visited[node]=1;
        for(auto &nbr: mp[node])
        {
            
            if(!visited[nbr])
            {
                reverse_dfs(visited,nbr,mp);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        vector<bool> visited(adj.size(),false);
        stack<int> sk;
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
            {
                dfs(sk,visited,adj,i);
            }
        }
        vector<vector<int>> rev(adj.size());
         for(int i =0;i<adj.size();i++)
        {
            for(auto &it : adj[i])
            {
                rev[it].push_back(i);
            }
        }
        vector<bool> reverse_visited(adj.size(),false);
        
        int component = 0;
        for(int i =0;i<adj.size();i++)
        {
            int top = sk.top();sk.pop();
            if(!reverse_visited[top])
            {
                reverse_dfs(reverse_visited,top,rev);
                component++;   
            }
        }
        return component;
    }
};
