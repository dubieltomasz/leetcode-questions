class Solution {
public:
    std::vector<int> sortJumbled(const std::vector<int>& mapping, const std::vector<int>& nums) {
        std::vector<std::pair<int, int>> mapped;
        std::vector<int> answer;
        
        for(const int& num : nums)
        {
            int tmp0 = 0;
            int tmp1 = num;
            int power = 1;

            do
            {
                tmp0 += mapping[tmp1 % 10] * power;
                tmp1 /= 10;
                power *= 10;
            } while(tmp1 > 0);

            mapped.push_back({num, tmp0});
        }

        std::sort(mapped.begin(), mapped.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) ->bool { return a.second < b.second; });

        for(const pair<int, int>& p : mapped)
            answer.push_back(p.first);
        
        return answer;
    }
};
