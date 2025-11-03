class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
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
            rank[y_par]+=1;
        }
        return;
    }
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        parent.resize(V);
        rank.resize(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        for(int i =0;i<V;i++)
        {
            for(auto &v: adj[i])
            {
                if(i<v)
                {
                    int x_par = find(i);
                    int y_par = find(v);
                    if(x_par==y_par)return true;
                    
                    unionSet(x_par,y_par);
                }
            }
        }
        return false;
    }
};
