/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) { return x.start < y.start; });
        int prevstart = intervals[0].start;
        int prevend = intervals[0].end;
        int n;
        n = intervals.size();
        for (int i = 1; i < n; i++) {
            int currstart = intervals[i].start;
            int currend = intervals[i].end;
            if (currstart < prevend) {
                return false;
            }
            prevstart = currstart;
            prevend = currend;
        }
        return true;
    }
};
