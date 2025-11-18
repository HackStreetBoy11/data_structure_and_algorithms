class Solution {
public:
    int fun(string answerKey,int k,char X)
    {
        int l=0,r=0;
        int len =0;
        int check=0;
        while(r<answerKey.size())
        {
            if(answerKey[r]==X)
            {
                check++;
            }
            while(check>k)
            {
                if(answerKey[l]==X)
                {
                    check--;
                }
                l++;
            }
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(fun(answerKey,k,'T'),fun(answerKey,k,'F'));
    }
};
