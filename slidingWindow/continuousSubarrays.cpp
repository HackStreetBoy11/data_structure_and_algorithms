class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l =0;
        int r=0;
        long long count=0;
        map<int,int> mp;
        while(r<nums.size())
        {
            mp[nums[r]]++;
            while(abs(mp.rbegin()->first -  mp.begin()->first)>2)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            count+=(r-l)+1;
            r++;
        }
        return count;
    }
};
