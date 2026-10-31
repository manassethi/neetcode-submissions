class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;
        output.push_back(intervals[0]);
        int n = intervals.size();

        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int last1 = output.back()[1];

            if (start2 <= last1) {
                output.back()[1] = max(intervals[i][1], last1);
            } else {
                output.push_back(intervals[i]);
            }
        }

        return output;
    }
};