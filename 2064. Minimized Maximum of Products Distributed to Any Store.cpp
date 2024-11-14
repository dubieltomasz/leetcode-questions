class Solution {
public:
    int minimizedMaximum(const int n, const std::vector<int>& quantities) {
        if(n == quantities.size()) return *std::max_element(quantities.begin(), quantities.end());

        int l = 1, r = *std::max_element(quantities.begin(), quantities.end()), m, result;

        while(l <= r)
        {
            m = l + r >> 1;

            n < canDistribute(m, quantities) ? l = m + 1 : r = m - 1;
        }

        return l;
    }

private:
    int canDistribute(const int k, const std::vector<int>& v)
    {
        int i = 0;

        for(const int& e : v)
            i += (e + k - 1) / k;

        return i;
    }
};
