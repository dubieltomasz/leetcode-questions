class Solution {
public:
    int findTheCity(const int n, const std::vector<std::vector<int>>& edges, const int distanceThreshold) {
        std::vector<std::vector<int>> distanceMatrix(n, std::vector<int>(n, 1e9));

        for(int i = 0; i < n; ++i)
            distanceMatrix[i][i] = 0;

        for(const std::vector<int>& edge : edges)
        {
            distanceMatrix[edge[0]][edge[1]] = edge[2];
            distanceMatrix[edge[1]][edge[0]] = edge[2];
        }

        floyd(n, distanceMatrix);

        return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
    }

private:
    void floyd(const int n, std::vector<std::vector<int>>& distanceMatrix)
    {
        for(int k = 0; k < n; ++k)
        {
            for(int i = 0; i < k; ++i)
            {
                for(int j = 0; j < i; ++j)
                    distanceMatrix[i][j] = std::min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);

                for(int j = i+1; j < n; ++j)
                    distanceMatrix[i][j] = std::min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);
            }

            for(int i = k+1; i < n; ++i)
            {
                for(int j = 0; j < i; ++j)
                    distanceMatrix[i][j] = std::min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);

                for(int j = i+1; j < n; ++j)
                    distanceMatrix[i][j] = std::min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);
            }
        }
    }

    int getCityWithFewestReachable(const int n, const std::vector<std::vector<int>>& shortestPathMatrix, const int distanceThreshold)
    {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        for(int i = 0; i < n; ++i)
        {
            int reachableCount = 0;

            for(int j = 0; j < i; ++j)
                if(shortestPathMatrix[i][j] <= distanceThreshold) ++reachableCount;

            for(int j = i+1; j < n; ++j)
                if(shortestPathMatrix[i][j] <= distanceThreshold) ++reachableCount;

            if(reachableCount <= fewestReachableCount)
            {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }

        return cityWithFewestReachable;
    }
};
