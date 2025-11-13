class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col,int n)
    {
        for(int i =0;i<n;i++)
        {
            if(i!=row && board[i][col]=='Q')return false;
        }
        for(int i=row,j=col;i>=0 && j>=0 ;i--,j--)
        {
            if(i!=row && j!=col && board[i][j]=='Q')return false;
        }
        for(int i=row,j=col;i>=0 && j<n ;i--,j++)
        {
            if(i!=row && j!=col && board[i][j]=='Q')return false;
        }
        return true;
    }
    void fun(vector<string>& board,vector<vector<string>>& result,int n,int row)
    {   
        if(row==n)
        {
            result.push_back(board);
            return;
        }
        for(int i =0;i<n;i++)
        {
            if(isSafe(board,row,i,n))
            {
                board[row][i]='Q';
                fun(board,result,n,row+1);
                board[row][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string temp;
        for(int i=0;i<n;i++)
        {
            temp+='.';
        }
        vector<string> board(n,temp);
        vector<vector<string>> result;
        fun(board,result,n,0);
        return result;
    }
};
