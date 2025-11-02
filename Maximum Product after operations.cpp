class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(int i =0;i<nums.size();i++)
            {
                if(nums[i]<0)
                {
                    nums[i]*=-1;
                }
            }
        sort(nums.begin(),nums.end());
        long long first,second;
        int n = nums.size();
        first = nums[n-1];
        second = nums[n-2];
        return first*second*100000;
    }
};
