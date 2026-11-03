class Solution {
   public:
    int f(int ind, vector<int>& coins, int amount, long long sum, vector<vector<int>>& dp) {
        if (ind >= coins.size()) {
            return 10001;
        }
        if (sum == amount) {
            return 0;
        }
        if (sum > amount) {
            return 10001;
        }

        if (dp[ind][sum] != -1) return dp[ind][sum];

        long long f1 = 1 + f(ind, coins, amount, sum + coins[ind], dp);
        long long f2 = f(ind + 1, coins, amount, sum, dp);

        return dp[ind][sum] = min(f1, f2);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount + 1, -1));

        int x = f(0, coins, amount, 0, dp);
        if (x >= 10001) return -1;
        return x;
    }
};
