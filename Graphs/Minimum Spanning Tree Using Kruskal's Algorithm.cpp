class Solution {
  public:
  
    vector<int>parent,rank;
    int find(int x)
    {
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    
    void unionSet(int x,int y)
    {
        int x_par =find(x);
        int y_par =find(y);
        
        if(x_par==y_par)return;
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
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++)parent[i]=i;
        
       
        sort(edges.begin(),edges.end(),[](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];
        });
        int sum=0;
        for(auto &it:edges)
        {
            int u= it[0];
            int v =it[1];
            int wt = it[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            if(parent_u!=parent_v)
            {
                unionSet(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
};
