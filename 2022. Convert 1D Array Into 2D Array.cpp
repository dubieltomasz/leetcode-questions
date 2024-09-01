class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(const std::vector<int>& original, int m, const int n) {
        if(m*n != original.size()) return {};

        int e = 0;
        std::vector<std::vector<int>> answer;
        answer.reserve(m);

        for(int i = 0; i < m; ++i)
        {
            answer.push_back(std::vector<int>(original.begin()+e, original.begin()+e+n));

            e += n;
        }

        return answer;
    }
};
