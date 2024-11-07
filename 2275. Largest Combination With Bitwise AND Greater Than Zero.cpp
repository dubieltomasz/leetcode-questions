class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        std::vector<int> v(24);
        int i, count = 0;

        for(int& candidate : candidates)
        {
            i = 0;
            
            do v[i++] += candidate & 1;
            while(candidate >>= 1);
        }
        
        return *max_element(v.begin(), v.end());
    }
};
