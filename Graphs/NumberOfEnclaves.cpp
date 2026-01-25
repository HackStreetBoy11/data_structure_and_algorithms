class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return ;
        if(board[i][j]!='O')return ;
        board[i][j]='#';
        // up 
        dfs(board, i-1,j);
        // right
        dfs(board, i , j+1);
        // down
        dfs(board,i+1,j);
        // left
        dfs(board,i,j-1);

    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c = board[0].size();
        for(int j=0;j<c;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(board,0,j);
            }
            if(board[r-1][j]=='O'){
                dfs(board, r-1,j);
            }
        }
        for(int i=0;i<r;i++)
        {
            if(board[i][0])
            {
                dfs(board,i,0);
            }
            if(board[i][c-1])
            {
                dfs(board,i,c-1);
            }
        }
        for(int i =0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
