// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
    
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it:edges)
        {
            int u = it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dp(V,INT_MAX);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<pair<int,int>> st;
        // pq.push({0,src});
        st.insert({0,src});
        dp[src]=0;
        while(!st.empty())
        {   auto &it = *st.begin();
            // int d = pq.top().first;
            // int node = pq.top().second;
            int d = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto &it:adj[node])
            {
                int dis =it.second;
                int nbr_node = it.first;
                if(dis+d <dp[nbr_node])
                {
                    if(dp[nbr_node]!=INT_MAX)
                    {
                        st.erase({dp[nbr_node],nbr_node});
                    }
                    dp[nbr_node]=dis+d;
                    st.insert({dis+d,nbr_node});
                }
            }
        }
        return dp;
    }
};
