class Solution {
public:

    void dfs(int node,unordered_map<int,vector<int>>&adj,int id,vector<bool>&visited,vector<int>&componentId,unordered_map<int,set<int>>&mp)
    {
        visited[node]=true;
        componentId[node]=id;
        mp[id].insert(node);
        for(auto &nbr:adj[node])
        {
            if(!visited[nbr])
            {
                dfs(nbr,adj,id,visited,componentId,mp);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto &it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int,set<int>>mp;  
        vector<int> componentId(c+1);

        vector<bool> visited(c+1,false);
        for(int node= 1;node<=c;node++) // O(v+E) dfs time is alwasy
        {
            if(!visited[node]){
                int component_id = node;
                dfs(node,adj,component_id,visited,componentId,mp);
            }
        }   
        vector<int> ans;

        for(auto &it:queries) //(O(Q))
        {
            int op = it[0];
            int station = it[1];

                int id = componentId[station];
            if(op==1)
            {
                if(mp[id].count(station))
                {
                    ans.push_back(station);
                }
                else if(mp[id].empty())
                {
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(*mp[id].begin());// log(V)
                }
            }
            else{
                mp[id].erase(station);
            }
        }
        return ans;// V+E + Q(log(V))
       
    }
};
