class Solution {
public:
    bool kLengthApart(const std::vector<int>& nums, const int k) {
        int dist = k;

        for(const int& num : nums) {
            if(num) {
                if(dist < k) {
                    return false;
                }

                dist = 0;
            } else {
                ++dist;
            }
        }

        return true;
    }
};
