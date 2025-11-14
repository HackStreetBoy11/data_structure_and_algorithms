class Solution {
public:
    vector<vector<int>> result;

    void fun(vector<int>& nums,int idx)
    {
        if(idx==nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            fun(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
    fun(nums,0);
    return result;
    }
};
