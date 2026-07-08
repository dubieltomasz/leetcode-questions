class Solution {
public:
    std::vector<int> sumAndMultiply(const std::string& s, const std::vector<std::vector<int>>& queries) {
        constexpr long mod = 1000000007;
        std::vector<int> answer(queries.size());

        std::vector<long> prefixValue(s.size() + 1), pow10(s.size() + 1, 1);
        std::vector<int> prefixLength(s.size() + 1), prefixSum(s.size() + 1);

        for(size_t i = 0; i < s.size(); ++i) {
            prefixValue[i + 1] = prefixValue[i];
            prefixLength[i + 1] = prefixLength[i];
            prefixSum[i + 1] = prefixSum[i];

            if(long character = static_cast<long>(s[i] - '0')) {
                prefixValue[i + 1] = (prefixValue[i] * 10 + character) % mod;
                ++prefixLength[i + 1];
                prefixSum[i + 1] = (prefixSum[i] + character) % mod;
            }
        }

        for(size_t i = 0; i < s.size(); ++i) {
            pow10[i + 1] = (pow10[i] * 10) % mod;
        }

        for(size_t i = 0; i < queries.size(); ++i) {
            const size_t l = queries[i][0], r = queries[i][1] + 1, length = prefixLength[r] - prefixLength[l];

            const long x = ((prefixValue[r] - prefixValue[l] * pow10[length]) % mod + mod) % mod;
            const long sum = (prefixSum[r] - prefixSum[l] + mod) % mod;

            answer[i] = static_cast<int>(x * sum % mod);
        }

        return answer;
    }
};
