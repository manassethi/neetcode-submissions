class Solution {
   public:
    bool check(const map<char, int>& mpp1,const map<char, int>& mpp2) {

        for(auto& el:mpp2){
            if(mpp1.find(el.first)==mpp1.end()) return false;
            auto ele=mpp1.find(el.first);
            if(el.second>ele->second) return false;
        }

        return true;



    }
    string minWindow(string s, string t) {
        map<char, int> mpp1;
        map<char, int> mpp2;
        for (auto c : t) {
            mpp2[c]++;
        }
        int n2 = t.length();
        int n1 = s.length();

        if (n2 > n1) return "";
        for (int i = 0; i < n2; i++) {
            mpp1[s[i]]++;
        }
        int l = 0;
        int r = n2 - 1;
        int ans_l = 0;
        int ans_r = 0;
        int len = n1+1;
        while (r < n1) {
            if (check(mpp1, mpp2)) {
                while (mpp2.find(s[l]) == mpp2.end() || mpp1[s[l]] > mpp2[s[l]]) {
                    mpp1[s[l]]--;
                    if (mpp1[s[l]] == 0) mpp1.erase(s[l]);
                    l++;
                }

                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ans_l = l;
                    ans_r = r;
                }
            }
            r++;
            mpp1[s[r]]++;
            
        }



        if(len<n1+1) return string(s.begin()+ans_l,s.begin()+ans_r+1);
        return "";
    }
};
