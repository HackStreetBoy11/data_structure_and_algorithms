class Solution {
  public:
    void fun_lps(string & pat,vector<int> &lps){
        int i=1;
        lps[0]=0;
        int len =0;
        int m = pat.size();
        while(i<m)
        {
            if(pat[i]==pat[len])
            {
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0)
                {
                    len = lps[len-1];
                }else{
                    len = 0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string &pat, string &txt) {
        // code here
        int m = pat.size();
        int n = txt.size();
        
        vector<int> lps(m,0);
        fun_lps(pat,lps);
        vector<int> ans;
        int i =0;
        int j=0;
        while(i<n)
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                ans.push_back(i-m);
                j  = lps[j-1];
            }else if(txt[i]!=pat[j]){
                if(j!=0)
                {
                    j= lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};
