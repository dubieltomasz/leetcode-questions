class Solution {
public:
    int rangeSum(const std::vector<int>& nums, const int& n, const int& left, const int& right) {
        constexpr int m = 1e9 + 7;
        long long answer = 0;
        long tmp;
        std::vector<long> v;
        v.reserve(n * (n+1) / 2);

        for(int i = 0; i < nums.size(); ++i)
        {
            tmp = 0;

            for(int j = i; j < nums.size(); ++j)
            {
                tmp += nums[j];

                v.push_back(tmp);
            }
        }

        sort(v.begin(), v.end());

        for(int i = left-1; i < right; ++i)
            answer += v[i];
        
        return answer % m;
    }
};
