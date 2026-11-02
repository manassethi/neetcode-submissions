class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n == 0 || n == 1) {
            return 0;
        }
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        for (int i = 1; i < height.size(); i++) {
            left[i] = max(left[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            ans += max(min(left[i], right[i]) - height[i], 0);
        }

        return ans;
    }
};
