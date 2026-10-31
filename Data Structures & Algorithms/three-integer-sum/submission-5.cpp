class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int t = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                long long f;
                f = nums[i] + nums[j] + nums[k];
                if (f == t) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (k > 0 && nums[k] == nums[k + 1]) k--;
                }
                else if (f < t) {
                    j++;

                } else {
                    k--;
                }
            }
        }

        return ans;
    }
};
