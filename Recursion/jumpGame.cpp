class Solution {
public:
    bool fun(int n ,vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=n-1)return true;
        if(dp[i]!=-1)return dp[i];
        for(int idx = 1;idx<=nums[i];idx++)
        {
            if(fun(n,nums,i+idx,dp)==true)
            {
                return dp[i]= true;
            }
        }
        return dp[i]= false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return fun(n,nums,0,dp);
    }
};
