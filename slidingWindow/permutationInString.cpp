class Solution {
public:
    bool is_safe(int arr1[],int arr2[])
    {
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=arr2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
     if(s1.size()>s2.size())return false;
    int sum[26]={0};
    for(char &c: s1)
    {
        sum[c-'a']++;
    }
    int n=s1.size();
    int check_sum[26]={0};
    int l=0,r=0;
    while(r<s2.size())
    {
        check_sum[s2[r]-'a']++;
        if(r-l+1==n)
        {
            if(is_safe(check_sum,sum))
            {
                return true;
            }
            check_sum[s2[l]-'a']--;
            l++;
        }

        r++;
    }
    return false;
    }
};
