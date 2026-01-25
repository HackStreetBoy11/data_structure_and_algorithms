class Solution {
  public:
    bool dfs(unordered_map<int,vector<int>>& adj,int curr,int par,vector<int>& visited)
    {
        visited[curr]=1;
        for(auto nbr:adj[curr])
        {
           if(!visited[nbr])
           {    if(dfs(adj,nbr,curr,visited))
               {
                   return true;  
               }
           }else if(par!=nbr)
           {
               return true;
           }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>> adj;
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(V,0);
        
        for(int i =0;i<V;i++)
        {
            if(!visited[i] && dfs(adj,i,-1,visited))
            {
                return true;
            }
        }
        return false;
    }
};
