// bfs solution
class Solution {
public:// apply dfs with different visited array 
    bool bfs(int node,vector<int>& visited,unordered_map<int,vector<int>>& adj,int color)
    {
        visited[node]=color;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int cur_node = q.front();
            q.pop();
            for(auto nbr:adj[cur_node])
            {
                if(visited[nbr]==-1)
                {
                    visited[nbr]=!visited[cur_node];
                    q.push(nbr);
                }
                if(visited[nbr]==visited[cur_node])
                {
                    return false;
                }
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
                if(!bfs(i,visited,adj,1))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
