class Solution
{
public:
    void dfs(vector<int> &visited, unordered_map<int, vector<int>> &adj,
             stack<int> &sk, int node)
    {
        visited[node] = 1;
        for (auto &nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfs(visited, adj, sk, nbr);
            }
        }
        sk.push(node);
        return;
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, vector<int>> adj;
        for (auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        stack<int> sk;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(visited, adj, sk, i);
            }
        }
        vector<int> ans;
        while (!sk.empty())
        {
            ans.push_back(sk.top());
            sk.pop();
        }
        return ans;
    }
};