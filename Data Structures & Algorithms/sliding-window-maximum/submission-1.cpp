class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int n = nums.size();
        multiset<int> st;
        int l = 0;
        int r = k - 1;
        for (int i = 0; i < k; i++) {
            st.insert(nums[i]);
        }

        
        
        while (r < n) {
            ans.push_back(*st.rbegin());
            st.erase(st.find(nums[l]));
            r++;
            if(r<n) st.insert(nums[r]);
            l++;
            
        }

        return ans;
    }
};
