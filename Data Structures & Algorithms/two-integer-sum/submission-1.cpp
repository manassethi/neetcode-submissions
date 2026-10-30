class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int val;
            val = v[i].first + v[j].first;

            if (val == target) {
                return {min(v[i].second, v[j].second), max(v[i].second, v[j].second)};
            } else if (val < target)
                i++;
            else
                j--;
        }
    }
};
