class Solution {
public:
// count proviences and return proviences -1
    void dfs(vector<int> & visited,unordered_map<int,vector<int>>&adj,int node)
    {
        visited[node]=1;
        for(auto &nbr:adj[node])
        {
            if(!visited[nbr])
            {
                dfs(visited,adj,nbr);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        unordered_map<int,vector<int>> adj;
            for(auto &vec: connections)
            {
                adj[vec[0]].push_back(vec[1]);
                adj[vec[1]].push_back(vec[0]);
            }
        vector<int> visited(n,0);
        int component=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {   component++;
                dfs(visited,adj,i);
            }
        }
        return component-1;
        
    }
};
