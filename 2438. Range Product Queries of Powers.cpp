class Solution {
public:
    std::vector<int> productQueries(int n, const std::vector<std::vector<int>>& queries) {
        std::vector<long long> powers;

        for(int i = 1; n >= i; i <<= 1) {
            if(n & i) {
                powers.push_back(i);
            }
        }

        std::vector<int> answers(queries.size());

        for(int i = 0; i < queries.size(); ++i) {
            long long product = powers[queries[i][1]];

            for(int j = queries[i][0]; j < queries[i][1]; ++j) {
                product *= powers[j];
                product %= 1000000007;
            }

            answers[i] = product;
        }

        return answers;
    }
};
