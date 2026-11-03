class Solution {
   public:
    static bool mycomp(pair<int, int>& p1, pair<int, int>& p2) { return p1.first < p2.first; }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(),mycomp);
        stack<double> st;

        for (int i = 0; i < n; i++) {
            double time =(double) (target - v[i].first) / v[i].second;
            while (!st.empty() && st.top() <= time) {
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};
