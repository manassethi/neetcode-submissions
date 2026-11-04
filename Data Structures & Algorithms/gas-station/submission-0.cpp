class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int x1 = accumulate(gas.begin(), gas.end(), 0);
        int x2 = accumulate(cost.begin(), cost.end(), 0);
        if (x1 < x2) return -1;
        int ans = 0;
        int tot = 0;
        for (int i = 0; i < gas.size(); i++) {
            tot += (gas[i] - cost[i]);
            if (tot < 0) {
                tot = 0;
                ans = i + 1;
            }
        }

        return ans;
    }
};
