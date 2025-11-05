class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:times)
        {
            int u = it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dp(n+1,INT_MAX);
        dp[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()) // v
        {
            auto [time,node]=pq.top();
            pq.pop();
            for(auto &it:adj[node])
            {
                int t = it.second;
                int nbr = it.first;

                if(t+time<dp[nbr])
                {
                    dp[nbr]=t+time;
                    pq.push({dp[nbr],nbr});
                }
            }
        } 
        int mini=INT_MIN;
        for(int i=1;i<=n;i++)
        {   
            mini = max(mini,dp[i]);
        }
        if(mini==INT_MAX)return -1;
        return mini;
    }
};
