class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, 0, target, {}, nums);
        return res;
    }

    void dfs(int i, int sum, int target, vector<int> curr, vector<int>& nums) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] + sum > target) return;

            curr.push_back(nums[j]);
            dfs(j, sum + nums[j], target, curr, nums);
            curr.pop_back();
        }
    }
};
