class Solution {
public:
    vector<vector<int>> result;
    void fun(vector<int>&nums,int idx)
    {
        if(idx==nums.size())
        {
            result.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=idx;i<nums.size();i++)
        {
            if(st.count(nums[i]))continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            fun(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        fun(nums,0);
        return result;

    }
};
