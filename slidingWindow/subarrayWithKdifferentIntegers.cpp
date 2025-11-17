class Solution {
public:
    int fun(vector<int>&nums,int k)
    {
        int l=0;
        int r=0;
        int count=0;
        unordered_map<int,int>mp;
        while(r<nums.size())
        {  mp[nums[r]]++;

            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            count+=(r-l+1); 
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // i have to find <=k and <k and substrat it to get =k
      return fun(nums, k) - fun(nums, k - 1);
    }
};
