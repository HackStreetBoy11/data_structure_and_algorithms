class Solution {
public:
    typedef pair<int,pair<int,int>> P;
   int dr[8] = {-1,-1,-1,0,1,1,1,0};
int dc[8] = {-1,0,1,1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
       priority_queue<P,vector<P>,greater<P>> q;
        q.push({1,{0,0}});// source
        vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
        visited[0][0]=0;
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1)
            {
                return dis;
            }
            for(int i=0;i<8;i++)    
            {
                    int nrow = dr[i]+r;
                    int ncol = dc[i]+c;

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && visited[nrow][ncol]!=1)
                    {
                        q.push({dis+1,{nrow,ncol}});
                        visited[nrow][ncol]=1;
                    }

            }

        }
        return -1;

    }
};
