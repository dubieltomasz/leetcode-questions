class Solution {
public:
    int secondMinimum(const int n, const std::vector<std::vector<int>>& edges, const int time, const int change) {
        std::vector<std::vector<int>> adj (n+1);
        std::vector<int> dist1 (n+1, -1), dist2 (n+1, -1);
        std::queue<std::pair<int, int>> q;

        for(const std::vector<int>& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dist1[1] = 0;
        q.push({1,1});

        while(!q.empty())
        {
            int node = q.front().first;
            int freq = q.front().second;
            q.pop();

            int timeTaken = (freq == 1 ? dist1[node] : dist2[node]);
            timeTaken = time + ((timeTaken / change) % 2 ? change * (timeTaken / change + 1) : timeTaken);

            for(const int& neighbor : adj[node])
            {
                if(dist1[neighbor] == -1)
                {
                    dist1[neighbor] = timeTaken;
                    q.push({neighbor, 1});
                }
                else if(dist2[neighbor] == -1 && dist1[neighbor] != timeTaken)
                {
                    if(neighbor == n) return timeTaken;
                    
                    dist2[neighbor] = timeTaken;
                    q.push({neighbor, 2});
                }
            }
        }

        return -1;
    }
};
