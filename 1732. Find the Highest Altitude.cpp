class Solution {
public:
    int largestAltitude(const std::vector<int>& gain) {
        int sum = 0, highiest = 0;

        for(const auto& val : gain) {
            highiest = std::max(highiest, sum += val);
        }

        return highiest;
    }
};
