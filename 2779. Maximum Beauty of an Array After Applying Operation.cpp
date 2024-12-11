class Solution {
public:
    int maximumBeauty(const std::vector<int>& nums, const int k) {
        std::vector<int> v(*max_element(nums.begin(), nums.end())+(k<<1)+2);
        int answer = 0, sum = 0;

        for(const int& num : nums)
        {
            ++v[num];
            --v[num + (k << 1) + 1];
        }

        for(const int& i : v)
            answer = std::max(answer, sum += i);

        return answer;
    }
};
