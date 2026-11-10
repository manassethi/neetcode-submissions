class Solution {
   public:
    int totsum;

    int f(int ind, vector<int>& nums, vector<vector<int>>& dp, int cursum, int target) {
        if (ind == nums.size()) {
            if (cursum == target) return 1;
            return 0;
        }

        if (dp[ind][cursum+totsum] != -1) return dp[ind][cursum+totsum];

        int f1 = f(ind + 1, nums, dp, cursum + nums[ind], target);
        int f2 = f(ind + 1, nums, dp, cursum - nums[ind], target);

        return dp[ind][cursum+totsum] = f1 + f2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totsum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * totsum + 1, -1));

        return f(0,nums,dp,0,target);



    }
};
