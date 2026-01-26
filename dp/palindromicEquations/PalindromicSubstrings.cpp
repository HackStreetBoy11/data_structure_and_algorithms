class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),0));
        for(int l=1;l<=s.size();l++){
            for(int i=0;i+l-1<s.size();i++)
            {
                int j = i+l-1;
                if(i==j)
                {
                    dp[i][j]=true;
                }
                else if(i+1==j)
                {
                    dp[i][j]=(s[i]==s[j]);
                }else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]==true)
                {
                    count++;
                }
                
            }
        }
        return count;
    }
};
