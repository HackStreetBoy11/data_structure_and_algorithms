class Solution {
public:

    bool isVowel( char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int maxi =0;
        int l=0;
        int r=0;
        int count=0;
        while(r<s.size())
        {
            if(isVowel(s[r]))
            {
                count++;
            }
            // update frequency
            // match condition
            if(r-l+1==k)
            {
                maxi = max(maxi,count);
                if(isVowel(s[l]))
                {
                    count--;
                }
                l++;
            }
            r++;
        }
        return maxi;
    }
};
