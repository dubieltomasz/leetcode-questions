class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        int remainingIntervals = intervals.size(), end = -1;

        std::sort(intervals.begin(), intervals.end(),
            [&](const auto& a, const auto& b) -> bool {
                return a[0] != b[0] ? a[0] < b[0] : b[1] < a[1];
            }
        );

        for(const auto& interval : intervals) {
            if(interval[1] > end) {
                end = interval[1];
            } else {
                --remainingIntervals;
            }
        }

        return remainingIntervals;
    }
};
