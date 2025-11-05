class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:edges)
        {
            int u = it[0];
            int v =it[1];
            int w =it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dp(n+1,INT_MAX);
        vector<int> parent(n+1,0);
        for(int i =0;i<n+1;i++)parent[i]=i;
        dp[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty()) // v
        {
            auto [dis,node] = pq.top();
            pq.pop(); // log v
            
            if(dis>dp[node])continue;
            for(auto &it:adj[node]) // e
            {
                int d = it.second;
                int nbr = it.first;
                if(d+dis<dp[nbr])
                {
                    dp[nbr]=d+dis;
                    parent[nbr]=node;
                    pq.push({d+dis,nbr}); // log v
                } 
            }
        }
        // total time - v*(log(v)+(e*log V)) = v log(V)+ evLog(v) = vlog(v)(1+e)
          if (dp[n] == INT_MAX) return {-1};  // No path
        vector<int> path;
        int prev =n;
        while(parent[prev]!=prev)
        {
            path.push_back(prev);
            prev = parent[prev];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        path.insert(path.begin(),dp[n]);// destination weight
        return path;
        
    }
};
