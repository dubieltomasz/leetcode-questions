class Solution {
public:
    int findChampion(const int n, const std::vector<std::vector<int>>& edges) {
        std::vector<bool> candidates(n, true);
        int champion = -1;
        
        for(const std::vector<int>& edge : edges)
            candidates[edge[1]] = false;

        for(int i = 0; i < n; ++i)
        {
            if(candidates[i])
            {
                if(champion == -1) champion = i;
                else return -1;
            }
        }

        return champion;
    }
};
