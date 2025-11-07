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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
         parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i < n; i++)
            parent[i] = i;

        vector<vector<int>> adj;
        for(int i =0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis = abs(points[j][0]-points[i][0])+abs(points[i][1]-points[j][1]); // 1-> 2 , 1->3, 1->4 no need for 2->1
                adj.push_back({i,j,dis});
            }
        }
        sort(adj.begin(),adj.end(),[](const vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });

       int sum=0;
        for(auto &it:adj)
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
