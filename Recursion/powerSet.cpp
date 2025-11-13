class Solution {
  public:
  vector<string> result;
    void fun(string s,int i, string temp)
    {
        if(i==s.size())
        {
            if(temp.size()!=0)
            {
                result.push_back(temp);
            }
            return;
        }
        
        fun(s,i+1,temp+s[i]);
        fun(s,i+1,temp);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        fun(s,0,"");
        sort(result.begin(),result.end());
        return result;
    }
};
