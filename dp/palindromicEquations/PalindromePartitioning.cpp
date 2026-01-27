class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<string>> result;
    void fun(string &s,int i,vector<string>& temp)
    {
        if(i==s.size())
        {
            result.push_back(temp);
            return ;
        }
        for(int j=i;j<s.size();j++)
        {
            if(dp[i][j])
            {
                temp.push_back(s.substr(i,j-i+1));
                fun(s,j+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dp.resize(s.size(),vector<int>(s.size(),0));
        for(int i =0;i<s.size();i++)
        {
            dp[i][i]=1;
        }
        for(int l=2;l<=s.size();l++){
            for(int i=0;i+l-1<s.size();i++){
                int j = i+l-1;
                if(s[i]==s[j])
                {
                    if(l==2){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]= dp[i+1][j-1];
                    }
                }
            }
        }
        vector<string> temp;
        fun(s,0,temp);
        return result;
    }
};
