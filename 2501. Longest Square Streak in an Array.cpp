class Solution {
public:
    int longestSquareStreak(const std::vector<int>& nums) {
        bool arr[100001]{};
        int answer = 0, count;
        unsigned long long tmp;

        for(const int& num : nums)
            arr[num] = true;
        
        for(int i = 1; i < 100000; ++i)
        {
            tmp = i;
            count = 0;

            while(tmp < 100000 && arr[tmp])
            {
                ++count;
                tmp *= tmp;
            }

            answer = std::max(answer, count);
        }

        return answer > 1 ? answer : -1;
    }
};
