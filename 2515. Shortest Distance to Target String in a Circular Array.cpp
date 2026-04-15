class Solution {
public:
    int closestTarget(const std::vector<std::string>& words, const std::string& target, const int startIndex) {
        const int n = words.size();
        int minDistance = words.size();

        for(int i = 0; i < n; ++i) {
            if(words[i] == target) {
                minDistance = std::min(
                    {minDistance, std::abs(startIndex - i), std::abs(i + n - startIndex), std::abs(startIndex + n - i)}
                );
            }
        }

        return minDistance == n ? -1 : minDistance;
    }
};
