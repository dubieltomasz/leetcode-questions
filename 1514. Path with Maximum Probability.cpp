class Solution {
public:
    double maxProbability(const int n, const std::vector<std::vector<int>>& edges, const std::vector<double>& succProb, const int start_node, const int end_node) {
        std::unordered_map<int, std::vector<std::pair<int, double>>> matrix;
        std::vector<double> D(n, 0);
        std::vector<int> P(n, -1);
        std::queue<int> q;
        int tmp;

        for(int i = 0; i < edges.size(); ++i)
        {
            matrix[edges[i][0]].push_back({edges[i][1], succProb[i]});
            matrix[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        q.push(start_node);
        D[start_node] = 1.0;

        while(!q.empty())
        {
            tmp = q.front();
            q.pop();

            for(const std::pair<int, double>& p : matrix[tmp])
            {
                if(D[p.first] < D[tmp]*p.second)
                {
                    D[p.first] = D[tmp]*p.second;
                    P[p.first] = tmp;
                    q.push(p.first);
                }
            }
        }

        return D[end_node];
    }
};
