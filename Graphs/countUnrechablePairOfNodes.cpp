class Solution {
public:
    vector<int> parent,rank;
    int find(int x)
    {
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void unionSet(int x,int y)
    {
        int x_par = find(x);
        int y_par = find(y);
        if(x_par==y_par)return ;
        if(rank[x_par]>rank[y_par])
        {
            parent[y_par]=x_par;   
        }
        else if(rank[x_par]<rank[y_par])
        {
            parent[x_par]=y_par;   
        }
        else{
             parent[x_par]=y_par;  
             rank[y_par]++;
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> adj;
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i =0;i<n;i++)
        {
            for(auto &it:adj[i])
            {   
                unionSet(i,it);
            }
        }
         for(int i =0;i<n;i++)
        {
            int parent = find(i);
                mp[parent]++;
        }
        long long result=0;
        long long remaining=n;
        for(auto &it:mp)
        {
            long long  size = it.second;
            result+= size*(remaining-size);
            remaining-=size;
        }
        return result;
    }
};
