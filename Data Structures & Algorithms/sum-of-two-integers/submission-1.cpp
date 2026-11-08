class Solution {
   public:
    int getSum(int a, int b) {
        int c = 0;
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            int d1 = (a >> i) & 1;
            int d2 = (b >> i) & 1;
            ans += (c ^ d1 ^ d2) << i;
            c = (c+d1 + d2) / 2;
        }

        return ans;
    }
};
