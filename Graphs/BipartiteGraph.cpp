class Solution {
public:// apply dfs with different visited array
    bool dfs(int node,vector<int>& visited,unordered_map<int,vector<int>>& adj,int color)
    {
        visited[node]=color;
        for(auto nbr:adj[node])
        {
            if(visited[nbr]==-1)
            {
                if(!dfs(nbr,visited,adj,!color))
                {
                    return false;
                }
            }
            if(visited[nbr]==color)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<graph.size();i++)
        {
            for(auto &v:graph[i]){
                adj[i].push_back(v);
            }
        }
        vector<int> visited(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==-1)
            {
                if(!dfs(i,visited,adj,1))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
