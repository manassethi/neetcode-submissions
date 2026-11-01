class Solution {
   public:
    int characterReplacement(string s, int k) {
        map<char, int> count;
        int l = 0;
        int r = 0;
        int maxf = 0;
        int ans = 0;
        int n = s.length();
        while (r < n) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
