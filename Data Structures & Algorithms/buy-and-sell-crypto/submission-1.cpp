class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> mini(n, INT_MAX);
        vector<int> maxi(n, INT_MIN);
        maxi[n - 1] = prices[n - 1];
        mini[0] = prices[0];
        int ans=0;

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                mini[i] = min(mini[i - 1], prices[i]);
                ans=max(ans,prices[i]-mini[i-1]);
            }

            
        }

        return ans;

        
    }
};
