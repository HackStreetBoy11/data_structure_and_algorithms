class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> letters(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++)
        {
            letters[i][i]=0;
        }
        for(int i=0;i<original.size();i++)
        {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            letters[u][v]=min(letters[u][v],cost[i]);
        }
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(letters[i][k]<INT_MAX && letters[k][j]<INT_MAX)
                    {
                        letters[i][j]=min(letters[i][j],letters[i][k]+letters[k][j]);
                    }
                }
            }
        }
        long long total =0;
        for(int i=0;i<source.size();i++)
        {
            int u = source[i]-'a';
            int v = target[i]-'a';
            if(letters[u][v]==INT_MAX)
            {
                return -1;
            }else{
                total+=letters[u][v];
            }
        }
        return total;
    }
};
