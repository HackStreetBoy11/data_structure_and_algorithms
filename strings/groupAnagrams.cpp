class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // mapped the sorted key to its anagrams 
        unordered_map<string,vector<string>> mp;
        for(string s: strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it: mp) // it will have structed key value 
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
