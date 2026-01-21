class Solution {
public:
    int fun_bs(vector<int>& ans,int target)
    {
        int l=0;
        int r=ans.size()-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(ans[mid]==target)return mid;
            if(ans[mid]<target){
                l=mid+1;
            }else{
                r= mid-1;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i =1;i<nums.size();i++)
        {
            int idx = fun_bs(ans,nums[i]);
            if(idx>=ans.size())
            {
                 ans.push_back(nums[i]); // input neww karna hai
                
            }else{
               ans[idx]=nums[i]; // overlapping karna hai
            }
        }
        return ans.size();
    }
};
