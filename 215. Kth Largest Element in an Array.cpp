class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());

        while(--k)
        {
            pop_heap(nums.begin(), nums.end());

            nums.pop_back();
        }

        return nums.front();
    }
};
