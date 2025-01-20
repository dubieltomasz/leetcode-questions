class Solution {
public:
    int firstCompleteIndex(const std::vector<int>& arr, const std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::array<int, 2>> lookup(m * n);
        std::vector<int> unpaintedInRow(m, n), unpaintedInCol(n, m);

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                lookup[mat[i][j]-1] = {i, j};

        for(int i = 0; i < arr.size(); ++i)
            if(!(--unpaintedInRow[lookup[arr[i]-1][0]] && --unpaintedInCol[lookup[arr[i]-1][1]]))
                return i;

        return -1;
    }
};
