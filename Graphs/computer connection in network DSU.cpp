class Solution {
public:
// count proviences and return proviences -1
   vector<int>parent,rank;
   int find(int x)
   {
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
   }
   void unionSet(int x,int y)
    {
        int x_par =find(x);
        int y_par = find(y);
        if(x_par == y_par)return;
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        unordered_map<int,vector<int>> adj;
            for(auto &vec: connections)
            {
                adj[vec[0]].push_back(vec[1]);
                adj[vec[1]].push_back(vec[0]);
            }
        int components = n;
        parent.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }

        for(int i =0;i<n;i++)
        {
            for(auto &v:adj[i])
            {
                if(i<v)
                {
                    int x_par = find(i);
                    int y_par = find(v);
                    if(x_par!=y_par)
                    {
                        unionSet(i,v);
                        components--;
                    }
                }
            }
        }
        return components-1;
    }
};
