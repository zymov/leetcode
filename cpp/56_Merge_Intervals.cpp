/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };

    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            int len = intervals.size();
            if(len == 0 || len == 1) return intervals;
            sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
                return a.start < b.start;
            });
            vector<Interval> res;
            res.push_back(intervals[0]);
            for(int i = 1; i < len; i++) {
                if(res.back().end >= intervals[i].start && res.back().end < intervals[i].end) {
                    res.back().end = intervals[i].end;
                } else if(res.back().end < intervals[i].start) {
                    res.push_back(intervals[i]);
                }
            }
            return res;
        }
    
};

int main() {
    Solution sol;
    return 0;
}

/*


*/