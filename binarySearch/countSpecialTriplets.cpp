class Solution {
public:
    int mod = 1e9+7;
    long long fun(int idx,vector<int>& temp){
        int ub = upper_bound(temp.begin(), temp.end(), idx) - temp.begin();
int lb = lower_bound(temp.begin(), temp.end(), idx) - temp.begin() - 1;
       
        int n=temp.size();
       return 1LL * (n - ub) * (lb + 1);
    }
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        long long count=0;
        for(int i=0;i<nums.size();i++){
            int key  = nums[i];
            if(mp.find(key*2) != mp.end() && mp[key*2].size()>=2){
                count+=fun(i,mp[key*2]);
            }
        }
        return (count)%mod;
    }
};
