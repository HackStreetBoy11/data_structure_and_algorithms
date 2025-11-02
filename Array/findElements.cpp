class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.size()==1)return {};
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int small = nums[0];
        int largest = nums[n-1];
        vector<int> ans;
        set<int> st;
        for(int num:nums)
            {
                st.insert(num);
            }
        for(int i =small;i<=largest;i++)
            {
                if(!st.count(i))
                {
                    ans.push_back(i);
                }
            }
        return ans;
    }
};
