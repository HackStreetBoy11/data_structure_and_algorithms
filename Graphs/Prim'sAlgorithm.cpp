class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it:edges)
        {
            adj[it[1]].push_back({it[0],it[2]});
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> visited(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            if(visited[node])continue;
            sum+=dis;
            visited[node]=1;
            for(auto &it:adj[node])
            {   int nbr= it.first;
            int d = it.second;
                if(!visited[nbr])
                {
                    pq.push({d,nbr});
                }
            }
        }
        return sum;
    }
};
