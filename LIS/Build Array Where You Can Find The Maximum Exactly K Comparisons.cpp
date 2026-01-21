class Solution {
public:
int mod = 1e9+7;
    int fun(int n,int m,int k,int i,int s,int mx,vector<vector<vector<int>>>&dp)
    {
        if(s>k)return 0;
        if(i==n)
        {
            if(k==s)return 1;
            return 0;
        }
        if(dp[i][mx][s]!=-1)return dp[i][mx][s];
        long long result=0;
        // for 0,1,2 
        // result+= 0 , 1, 2 indexes baby easy
        for(int j=1;j<=m;j++)
        {
            if(mx<j)
            {
                result+=fun(n,m,k,i+1,s+1,j,dp);
            }
            else{
                result+=fun(n,m,k,i+1,s,mx,dp);
            }
            result%=mod;
        }
        return dp[i][mx][s]= result;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return fun(n,m,k,0,0,0,dp);
    }
};
