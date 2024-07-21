class Solution {
public:
    std::vector<std::vector<int>> buildMatrix(const int& k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
        std::vector<int> orderRows = topoSort(rowConditions, k);
        std::vector<int> orderColumns = topoSort(colConditions, k);

        if(orderRows.empty() || orderColumns.empty()) return {};

        std::vector<std::vector<int>> matrix(k, std::vector<int> (k));

        for(int i = 0; i < k; ++i)
        {
            for(int j = 0; j < k; ++j)
            {
                if(orderRows[i] == orderColumns[j])
                {
                    matrix[i][j] = orderRows[i];
                    break;
                }
            }
        }

        return matrix;
    }

private:
    std::vector<int> topoSort(const std::vector<std::vector<int>>& edges, int n)
    {
        std::vector<std::vector<int>> adj(n + 1);
        std::vector<int> deg(n + 1), order;

        for(const std::vector<int>& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            ++deg[edge[1]];
        }

        std::queue<int> q;

        for(int i = 1; i <= n; ++i)
            if(!deg[i]) q.push(i);

        while(!q.empty())
        {
            int f = q.front();
            q.pop();

            order.push_back(f);

            --n;

            for(const int& v : adj[f])
                if(--deg[v] == 0) q.push(v);
        }

        if(n) return {};
        else return order;
    }
};
