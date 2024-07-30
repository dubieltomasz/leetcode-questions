class Solution {
public:
    int minimumDeletions(const std::string& s) {
        int min_deletions = 0, b_count = 0;

        for(const char& c : s)
            c == 'a' ? min_deletions = std::min(min_deletions+1, b_count) : ++b_count;

        return min_deletions;
    }
};
