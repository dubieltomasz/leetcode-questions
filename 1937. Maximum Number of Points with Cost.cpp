class Solution {
public:
    long long maxPoints(const std::vector<std::vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        std::vector<long long> v1(n), v2(n);
        long long answer = 0, tmp;

        for(const std::vector<int>& row : points)
        {
            tmp = 0;

            for(int j = 0; j < n; ++j)
            {
                tmp = std::max(tmp-1, v1[j]);
                v2[j] = tmp;
            }

            tmp = 0;

            for(int j = n-1; j > -1; --j)
            {
                tmp = std::max(tmp-1, v1[j]);
                v2[j] = std::max(v2[j], tmp) + row[j];
            }

            v1 = v2;
        }

        for(const long long& ll : v1)
            answer = std::max(answer, ll);

        return answer;
    }
};
