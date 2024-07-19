class Solution {
public:
    std::vector<int> luckyNumbers (const std::vector<std::vector<int>>& matrix) {
        int m, I, J, r;

        for(int i = 0; i < matrix.size(); ++i)
        {
            m = INT_MAX;

            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(matrix[i][j] < m)
                {
                    m = matrix[i][j];
                    I = i;
                    J = j;
                }
            }

            m = -INT_MAX;
            r = 0;

            while(r < matrix.size())
            {
                if(matrix[I][J] < matrix[r][J]) break;
                else ++r;
            }

            if(r == matrix.size()) return {matrix[I][J]};
        }

        return {};
    }
};
