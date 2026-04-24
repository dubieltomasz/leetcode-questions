class Solution {
public:
    int maxDistance(const std::vector<int>& colors) {
        int dist = 0, col = colors.front();
        std::vector<std::pair<int, int>> v = {};
        v.reserve(colors.size());

        for(const int& color : colors) {
            if(color == col) {
                ++dist;
            } else {
                v.push_back({dist, col});
                dist = 1;
                col = color;
            }
        }
        v.push_back({dist, col});

        int l = 0, r = v.size() - 1;

        while(v[l].second == v[r].second) {
            if(v[l].first > v[r].first) {
                --r;
            } else {
                ++l;
            }
        }

        dist = 0;

        for(int i = l; i <= r; ++i) {
            dist += v[i].first;
        }

        return dist - 1;
    }
};
