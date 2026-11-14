class Solution {
   public:
    int f(int ind, int curr, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (curr > amount) return 0;
        if (curr == amount) return 1;
        if (ind == coins.size()) {
            if (curr == amount) return 1;
            return 0;
        }
        if (dp[ind][curr] != -1) return dp[ind][curr];
        int op1 = f(ind + 1, curr, amount, coins, dp);
        int op2 = f(ind, curr + coins[ind], amount, coins, dp);

        return dp[ind][curr] = op1 + op2;
    }
    int change(int amount, vector<int>& coins) { 
        sort(coins.begin(), coins.end());

        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));

        return f(0,0,amount,coins,dp);

        
    }
};
