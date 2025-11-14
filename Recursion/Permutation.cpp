class Solution {
public:
vector<vector<int>> result;
unordered_set<int> st;
    void fun(vector<int>& nums,vector<int>temp)
    {
        if(temp.size()==nums.size())
        {
            result.push_back(temp);
            return;
        }
        for(int k =0;k<nums.size();k++)
        {
            if(!st.count(nums[k]))
            {   st.insert(nums[k]);
                temp.push_back(nums[k]);
                fun(nums,temp);
                st.erase(nums[k]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        fun(nums,temp);
        return result;
    }
};
