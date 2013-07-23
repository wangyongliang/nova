/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i ++) {
          if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.start) {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);

          } else {
            if (intervals[i].end > newInterval.start && !inserted) {
              inserted = true;
              result.push_back(newInterval);
            }
            result.push_back(intervals[i]);
          }
        }
        if (!inserted) {
          result.push_back(newInterval);
        }
        return result;
    }
};