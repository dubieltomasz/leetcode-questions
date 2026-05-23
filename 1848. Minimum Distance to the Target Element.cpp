class Solution {
public:
    int getMinDistance(const std::vector<int>& nums, const int target, const int start) {
        const int checkBothDirections = std::min(static_cast<size_t>(start), nums.size() - start - 1);
        int offset = 0;

        while(offset <= checkBothDirections) {
            if(nums[start - offset] == target
            || nums[start + offset] == target) {
                return offset;
            }

            ++offset;
        }

        if(start - offset > 0) {
            for(int i = start - offset - 1; i >= 0; --i) {
                if(nums[i] == target) {
                    return start - i;
                }
            }
        } else {
            for(int i = start + offset + 1; i < nums.size(); ++i) {
                if(nums[i] == target) {
                    return i - start;
                }
            }
        }

        return -1;
    }
};
