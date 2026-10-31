class Solution {
   public:
    bool f(int mid, int h, vector<int>& piles) {
        long long ans = 0;
        for (auto& el : piles) {
            ans += (el + mid - 1) / mid;
        }

       return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long l = 1;
        long long r=1e9;
        long long ans = 1;

        while (l <= r) {
            long long mid;
            mid = (l + r) / 2;
            if (f(mid, h, piles)) {
                ans = mid;
                r = mid - 1;

            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
