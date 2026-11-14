class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;

        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            heap.push({nums[i], i});
            if (i >= k - 1) {
                int ind = heap.top().second;
                while (ind <= i - k) {
                    heap.pop();
                    ind=heap.top().second;
                }

                ans.push_back(heap.top().first);
            }
        }

        return ans;
    }
};
