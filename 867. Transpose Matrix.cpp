class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        if(matrix[0].size() == matrix.size())
        {
            for(unsigned long i = 0; i < matrix.size(); ++i)
                for(unsigned long j = i+1; j < matrix.size(); ++j)
                {
                    matrix[j][i] ^= matrix[i][j];
                    matrix[i][j] ^= matrix[j][i];
                    matrix[j][i] ^= matrix[i][j];
                }

            return matrix;
        }
        else
        {
            vector<vector<int>> m(matrix[0].size(), vector<int>(matrix.size()));
            
            for(unsigned long i = 0; i < matrix[0].size(); ++i)
                for(unsigned long j = 0; j < matrix.size(); ++j)
                    m[i][j] = matrix[j][i];

            return m;
        }
    }
};
