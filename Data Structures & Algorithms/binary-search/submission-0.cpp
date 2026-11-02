class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int t = nums[mid];
            if(t==target) return mid;
            if(t<target) l=mid+1;
            if(t>target) r=mid-1;


        }

        return -1;
    }
};
