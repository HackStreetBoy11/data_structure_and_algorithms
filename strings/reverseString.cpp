class Solution {
public:
    void fun(vector<char>& ans,vector<char>& s,int i)
    {
        if(i==s.size())
        {
            return ;
        }
        fun(ans,s,i+1);// suppose you are at 5 and move to 6th index then came back now put value at index 5 
        ans.push_back(s[i]);
    }
    void reverseString(vector<char>& s) {
        vector<char> ans;
        fun(ans,s,0);
        s=ans;
    }
};
