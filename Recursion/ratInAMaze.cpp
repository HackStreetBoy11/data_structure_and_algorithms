class Solution {
  public:
        
    void dfs(vector<vector<int>>& maze,int n , vector<vector<int>>& visited,vector<string>&result,string temp,int i,int j)
    {
        if(i>=n ||j>=n ||i<0 || j<0 ||visited[i][j] || !maze[i][j])return;
        if(i==n-1&& j==n-1)
        {
            result.push_back(temp);
            return ;
        }
        visited[i][j]=1;
        dfs(maze,n,visited,result,temp+'U',i-1,j);
        dfs(maze,n,visited,result,temp+'R',i,j+1);
        dfs(maze,n,visited,result,temp+'D',i+1,j);
        dfs(maze,n,visited,result,temp+'L',i,j-1);
        visited[i][j]=0;
    }
        
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        if(!maze[0][0]|| !maze[n-1][n-1])return {};
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string> result;
        string temp="";
        dfs(maze,n,visited,result,temp,0,0);
        sort(result.begin(),result.end());
        return result;
    }
};
