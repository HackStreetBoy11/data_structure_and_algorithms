// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dis(V,1e8);
        dis[src]=0;
        
        for(int i =1;i<V;i++)
        {
            for(auto &edge :edges)
            {
                int u = edge[0];
                int v= edge[1];
                int w = edge[2];
                
                if(dis[u]!=INT_MAX && dis[u]+w <dis[v])
                {
                    dis[v]=dis[u]+w;
                }
            }
        }
        // in final traversal if any distance got updated means there is a negative cycle
        for(auto &edge :edges)
            {
                int u = edge[0];
                int v= edge[1];
                int w = edge[2];
                
                if(dis[u]!=INT_MAX && dis[u]+w <dis[v])
                {
                    dis[v]=dis[u]+w;
                    return {-1};
                }
            }
            return dis;
    }
};
