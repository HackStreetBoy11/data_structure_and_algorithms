class Solution {
public:
    bool isZero(vector<int>& freq)
    {
        for(int &i: freq)
        {
            if(i!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq(26,0);
        for(int i =0;i<p.size();i++)
        {
            freq[p[i]-'a']++;
        }
        int l=0,r=0;
        vector<int> indexes;
        while(r<s.size())
        {
            freq[s[r]-'a']--;
            if(r-l+1==p.size())
            {
                if(isZero(freq))
                {
                    indexes.push_back(l);
                }
                freq[s[l]-'a']++;
                l++;
            }
            r++;
        }
        return indexes;
    }
};
