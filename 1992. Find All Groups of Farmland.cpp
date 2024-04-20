class Solution {
private:
    vector<int> measureLand(vector<vector<int>>& matrix, const int& m, const int& n, const int& i, const int& j)
    {
        int I = i, J = j, tmp_i = i, tmp_j;

        matrix[I][J] = 2;

        while(I+1 < m && matrix[I+1][J] == 1)
        {
            ++I;
            matrix[I][J] = 2;
        }
        
        while(J+1 < n && matrix[I][J+1] == 1)
        {
            ++J;
            matrix[I][J] = 2;
        }

        while(tmp_i < I)
        {
            tmp_j = j+1;

            while(tmp_j <= J) matrix[tmp_i][tmp_j++] = 2;

            ++tmp_i;
        }

        return {i, j, I, J};
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> answer{};

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(land[i][j] == 1)
                    answer.push_back(measureLand(land, m, n, i, j));

        return answer;
    }
};
