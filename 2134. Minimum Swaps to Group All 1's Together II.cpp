class Solution {
public:
    int minSwaps(const std::vector<int>& nums) {
        int amountOfOnes = accumulate(nums.begin(), nums.end(), 0);

        if(amountOfOnes == nums.size()) return 0;

        int crntAmount = accumulate(nums.begin(), nums.begin()+amountOfOnes, 0);
        int answer = amountOfOnes-crntAmount;

        for(int i = 0; i < nums.size()-1; ++i)
        {
            crntAmount += nums[(i+amountOfOnes) % nums.size()] - nums[i];

            answer = std::min(answer, amountOfOnes-crntAmount);
        }

        return answer;
    }
};
