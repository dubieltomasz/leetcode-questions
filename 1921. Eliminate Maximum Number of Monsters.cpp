const static void __attribute__((constructor)) _() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, const std::vector<int>& speed) {
        int n = dist.size();

        #pragma unroll
        for(int i = 0; i < n; ++i) {
            dist[i] = (dist[i] - 1) / speed[i];
        }

        std::sort(dist.begin(), dist.end());

        #pragma unroll
        for(int minute = 0; minute < n; ++minute) {
            if(minute > dist[minute]) {
                return minute;
            }
        }

        return n;
    }
};
