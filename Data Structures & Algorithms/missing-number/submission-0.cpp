class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int tot = nums.size();

        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < tot; i++) {
            ans1 = ans1 ^ nums[i];
            ans2 = ans2 ^ i;
        }

        ans2 = ans2 ^ tot;
        return ans1 ^ ans2;
    }
};
