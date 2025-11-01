class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
          vector<int> indegree(V,0);
        unordered_map<int,vector<int>> adj;
        queue<int> q;
        for(auto & edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        for(int i =0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &nbr: adj[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
        return ans.size() != V;
    }
};
