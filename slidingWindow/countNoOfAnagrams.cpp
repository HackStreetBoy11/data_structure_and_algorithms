// User function template for C++
class Solution {
  public:
  
     bool isZero(vector<int>&counter)
        {
          for(int &i:counter)
          {
              if(i!=0)
              {
                  return false;
              }
          }
          return true;
        }
    int search(string &pat, string &txt) {
        // code here
        
     
        vector<int> counter(26,0);
        for(int i=0;i<pat.size();i++)
        {
            counter[pat[i]-'a']++;
        }
        int l=0,r=0;
        int count=0;
        while(r<txt.size())
        {
            counter[txt[r]-'a']--;
            if(r-l+1==pat.size())
            {
                if(isZero(counter))
                {
                    count++;
                }
                counter[txt[l]-'a']++;
                l++;
            }
            r++;
        }
        return count;
    }
};
