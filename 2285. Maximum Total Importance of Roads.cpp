class Solution {
public:
    long long maximumImportance(int n, const vector<vector<int>>& roads) {
        std::vector<int> v(n);
        long long answer = 0;

        for(const std::vector<int>& road : roads)
        {
            ++v[road[0]];
            ++v[road[1]];
        }

        std::sort(v.begin(), v.end(), std::greater<int>());

        for(const int& i : v)
            answer += (long long)i * n--;

        return answer;
    }
};
