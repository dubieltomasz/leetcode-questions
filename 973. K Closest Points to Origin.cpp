class Solution {
public:
    std::vector<std::vector<int>> kClosest(const std::vector<std::vector<int>>& points, const int& k) {
        if(k == points.size()) return points;

        std::vector<std::vector<int>> answer(k);
        std::vector<std::pair<int, int>> v;

        for(int i = 0; i < points.size(); ++i)
            v.push_back({points[i][0]*points[i][0]+points[i][1]*points[i][1], i});

        std::sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;});

        for(int i = 0; i < k; ++i)
            answer[i] = points[v[i].second];

        return answer;
    }
};
