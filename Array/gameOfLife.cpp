class Solution {
public:
    int dr[8]={-1,-1,-1,0,1,1,1,0};
    int dc[8]={-1,0,1,1,1,0,-1,-1};
    // ones<2 dead, >3 dead,
    // ones >=2 && <=3 alive
    // ones ==3 dead == alive
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>board1=board;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   int count=0;
                for(int k=0;k<8;k++)
                {
                    int nrow = dr[k]+i;
                    int ncol = dc[k]+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol])
                    {
                        count++;
                    }
                }
                if(count<2 ||count>3 )
                {
                    board1[i][j]=0;
                }
                else if(count==3)
                {
                    board1[i][j]=1;
                }
            }
        }
        board = board1;
    }
};
