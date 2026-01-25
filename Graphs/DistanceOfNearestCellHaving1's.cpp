class Solution {
  public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        
        queue<pair<int,pair<int,int>>> q; // {step, node}
        // i thought if i got all ones in a queeu
        
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i =0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({0,{i,j}});
                    visited[i][j]=1;
                    grid[i][j]=-1;
                }
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int step = it.first;
            int i = it.second.first;
            int j =it.second.second;
            
            for(int k =0;k<4;k++)
            {
                int i_ = dx[k]+i;
                int j_ = dy[k]+j;
                
                if( i_>=0 && i_<grid.size()&& j_>=0 && j_<grid[0].size() && grid[i_][j_]==0 && !visited[i_][j_])
                {
                    grid[i_][j_]=step+1;
                    visited[i_][j_]=1;
                    q.push({step+1,{i_,j_}});
                }
            }
        }
        for(int i =0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==-1)
                {
                    grid[i][j]=0;
                }
            }
        }
        return grid;
    }
};
