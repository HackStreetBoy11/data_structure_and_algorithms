class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> pref(nums.size(),0),suff(nums.size(),0);
        int p=1,s=1;
        int maximum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(p==0)p=1;
            if(s==0)s=1;
            p=p*nums[i];
            s=s*nums[nums.size()-1-i];
            maximum=max(maximum,max(p,s));
        }
        return maximum;
    }
};
