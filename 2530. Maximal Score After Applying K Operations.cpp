class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());
        long long answer = 0;

        while(k--)
        {
            std::pop_heap(nums.begin(), nums.end());
            answer += nums.back();

            nums.back() = (nums.back() + 2) / 3;
            std::push_heap(nums.begin(), nums.end());
        }

        return answer;
    }
};
