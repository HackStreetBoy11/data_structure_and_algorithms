class Solution {
public:
    string longestPalindrome(string s) {
        
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));

        for(int i =0;i<s.size();i++)
        {
            dp[i][i]=1;
        }
        int idx=0;
        int maxlen =1;
        for(int l=2;l<=s.size();l++)
        {
            for(int i=0;i+l-1<s.size();i++)
            {
                int j = i+l-1;
                if(s[i]==s[j] && l==2)
                {
                    dp[i][j]=1;
                    maxlen = 2;
                    idx= i;
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    if(maxlen <l){
                        maxlen = l;
                        idx = i;
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return s.substr(idx,maxlen);
    }
};
