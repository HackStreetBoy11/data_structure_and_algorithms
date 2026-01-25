// User function Template for C++

class Solution {
  public:
  set<vector<pair<int,int>>> st;
  int dx[4]={-1,0,1,0};
  int dy[4]={0,1,0,-1};
  void bfs(vector<vector<int>>& grid,int x, int y,vector<vector<int>>& visited)
  {
      visited[x][y]=1;
      queue<pair<int,int>> q;
      q.push({x,y});
      vector<pair<int,int>> temp;
      while(!q.empty())
      {
          auto [x_,y_]=q.front();
          q.pop();
          
          temp.push_back({x-x_,y-y_});
          for(int i=0;i<4;i++)
          {
              int nbr_x = dx[i]+x_;
              int nbr_y = dy[i]+y_;
               if (nbr_x >= 0 && nbr_x < grid.size() &&
                    nbr_y >= 0 && nbr_y < grid[0].size() &&
                    grid[nbr_x][nbr_y] == 1 &&
                    !visited[nbr_x][nbr_y])
                {
                    visited[nbr_x][nbr_y] = 1;
                    q.push({nbr_x, nbr_y});
                }
          }
      }
      st.insert(temp);
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int r=grid.size();
        int c= grid[0].size();
        vector<vector<int>> visited(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    bfs(grid,i,j,visited);
                }
            }
        }
        return st.size();
    }
};
