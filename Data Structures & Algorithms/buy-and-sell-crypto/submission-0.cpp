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
            }
            if (i < n - 1) {
                maxi[n - i - 2] = max(maxi[n - i - 1], prices[n - i - 2]);
            }
        }

        for(int i=0;i<n-1;i++){
            ans=max(ans,maxi[i+1]-mini[i]);
        }

        return ans;
    }
};
