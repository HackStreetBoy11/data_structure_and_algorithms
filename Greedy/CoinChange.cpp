class Solution {
public:
    map<string,int> dp;
    int fun(vector<int>& coins, int amount, int i){
        if(amount == 0) return 0;
        if(i == coins.size()) return INT_MAX;
        string key = to_string(amount)+'#'+to_string(i);
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        int take = INT_MAX;
        int not_take = INT_MAX;

        if(amount >= coins[i]){
            int p = fun(coins, amount - coins[i], i); // stay on same coin
            if(p != INT_MAX){
                take = 1 + p;
            }
        }

        not_take = fun(coins, amount, i+1);

        return dp[key]= min(take, not_take); // minimize coins
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        
        int coin = fun(coins, amount, 0);
        return coin == INT_MAX ? -1 : coin;
    }
};
