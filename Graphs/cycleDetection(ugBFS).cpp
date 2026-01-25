class Solution {
  public:
   
   bool bfs(unordered_map<int,vector<int>>& adj,int curr,int par,vector<int>& visited)
   {
       visited[curr]=1;
       
       queue<pair<int,int>> q;
       q.push({curr,-1});
       while(!q.empty())
       {
          auto it = q.front();
          q.pop();
          int node = it.first;
          int par =  it.second;
          for(auto nbr:adj[node]){
              if(!visited[nbr])
              {
                q.push({nbr,node});
                visited[nbr]=true;
              }else if( nbr!=par)
              {
                  return true;
              }
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
            if(!visited[i] && bfs(adj,i,-1,visited))
            {
                return true;
            }
        }
        return false;
    }
};
