class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
    auto  lambda= [&](string &a,string &b){
        return a.size()<b.size();
    };
    sort(words.begin(),words.end(),lambda);
    unordered_map<string ,int> dp;
    int ans= 1;
    for(string &s:words)
    {
        dp[s]=1;
        for(int i=0;i<s.size();i++)
        {
            string pre = s.substr(0,i)+s.substr(i+1); 
            if(dp.count(pre))
            {
                dp[s]=max(dp[s],dp[pre]+1);
            }
        }
        ans = max(ans,dp[s]);
    }
    return ans;
    
    // n * m * m
    }
};
