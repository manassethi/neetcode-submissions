class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> last;
        int l = 0;
        int r = 0;
        int ans = 0;

        while (r < n) {
            auto it = last.find(s[r]);
            if (it != last.end() && it->second>=l) {
                l = it->second + 1;
            }
            last[s[r]] = r;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
