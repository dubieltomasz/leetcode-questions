class Solution {
public:
    std::vector<int> missingRolls(const std::vector<int>& rolls, int mean, int n) {
        mean *= n+rolls.size();

        for(const int& i : rolls)
            mean -= i;

        if(mean > 6 * n || mean < n)
            return {};

        int x = mean / n;
        std::vector<int> answer(n, x);

        for(int i = 0; i < mean % n; ++i)
            ++answer[i];

        return answer;
    }
};
