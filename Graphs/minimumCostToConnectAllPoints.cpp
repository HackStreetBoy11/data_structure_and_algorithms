class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i =0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis = abs(points[j][0]-points[i][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int> visited(n,0);
        int sum=0;
        while(!pq.empty())
        {
            auto it = pq.top();
            int dis = it.first;
            int node =it.second;
            pq.pop();
            if(visited[node])continue;
            sum+=dis;
            visited[node]=1;
            for(auto &nbr:adj[node])
            {
                if(!visited[nbr.first])
                {
                    pq.push({nbr.second,nbr.first});
                }
            }
        }
        return sum;
    }
};
