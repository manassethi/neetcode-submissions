class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mpp;

        int ans = 0;

        for (int num : nums) {
            if (!mpp[num]) {
                mpp[num] = mpp[num - 1] + mpp[num + 1] + 1;
                mpp[num - mpp[num - 1]] = mpp[num];
                mpp[num + mpp[num + 1]] = mpp[num];
                ans = max(ans, mpp[num]);
            }
        }

        return ans;
    }
};
