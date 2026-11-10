class Solution {
   public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[buy][i] != -1) return dp[buy][i];
        int f1 = 0;
        int f2 = 0;
        if (buy) {
            f1 = -1 * prices[i] + f(i + 1, 0, prices, dp);
            f2 = f(i + 1, 1, prices, dp);
        } else {
            f1 = prices[i] + f(i + 2, 1, prices, dp);
            f2 = f(i + 1, 0, prices, dp);
        }

        return dp[buy][i] = max(f1, f2);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, -1));
        return f(0, 1, prices, dp);
    }
};
