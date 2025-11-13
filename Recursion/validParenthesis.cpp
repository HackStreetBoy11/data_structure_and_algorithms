class Solution {
public:

vector<string> result;
    void solve(int n,string curr,int open,int close)
    {
        if(curr.size()== 2*n)
        {
            result.push_back(curr);
            return ;
        }
        if(open<n)
        {
            solve(n,curr+'(',open+1,close);
        }
        if(open>close)
        {
            solve(n,curr+')',open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;//'('
        int close = 0; //')'
        solve(n,"",open,close);
        return result;
    }
};
