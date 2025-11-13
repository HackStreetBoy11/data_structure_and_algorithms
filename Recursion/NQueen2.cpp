class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col,int n)
    {
        for(int i =0;i<n;i++)
        {
            if(i!=row && board[i][col]=='Q')return false;
        }
        for(int i =row-1,j=col-1;i>=0 && j>=0 ; i--,j--)
        {
            if(board[i][j]=='Q')return false;
        }
        for(int i =row-1,j=col+1;i>=0 && j>=0 ; i--,j++)
        {
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void fun(vector<vector<string>>& result,vector<string>& board,int n, int row)
    {
        if(row==n){result.push_back(board);
        return ;}

        for(int i =0;i<n;i++)
        {
            if(isSafe(board,row,i,n))
            {
                board[row][i]='Q';
                fun(result,board,n,row+1);
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        string temp;
        for(int i=0;i<n;i++)temp+='.';
        vector<string> board(n,temp);
        vector<vector<string>> result;
        fun(result,board,n,0);
        return result.size();
    }
};
