/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 // 空间复杂度：O(n)
 // 时间复杂度：O(nlogn)
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), [&](Interval& a, Interval& b){
            return a.start < b.start;
        });
        int n = intervals.size();
        vector<Interval> res;
        for (int i = 0; i < n; i++) {
            int L = intervals[i].start, R = intervals[i].end;
            if (res.empty() || res.back().end < L) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, R);
            }
        }
        return res;
    }
};