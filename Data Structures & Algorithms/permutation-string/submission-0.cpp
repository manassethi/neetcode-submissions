class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), n2 = s2.length();
        if (n > n2) return false;

        map<char, int> mpp1, mpp2;
        for (char c : s1) mpp1[c]++;
        for (int i = 0; i < n; i++) mpp2[s2[i]]++;

        if (mpp1 == mpp2) return true; //if the lengths are exactly the same. First check

        for (int i = n; i < n2; i++) {
            mpp2[s2[i]]++;
            if (--mpp2[s2[i - n]] == 0) mpp2.erase(s2[i - n]);
            if (mpp1 == mpp2) return true;
        }
        return false;
    }
};