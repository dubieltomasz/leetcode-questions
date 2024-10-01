class Solution {
public:
    bool canArrange(const std::vector<int>& arr, const int k) {
        std::vector<int> v(k, 0);

        for(const int& i : arr)
            ++v[(i % k + k) % k];
        
        if(v.front() % 2) return false;

        for(int i = 1; i <= k/2; ++i)
            if(v[i] != v[k - i]) return false;

        return true;
    }
};
