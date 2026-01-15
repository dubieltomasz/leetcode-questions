class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
        int maxWidth = m ? vBars.size() ? 2 : 1 : 0, maxHeight = n ? hBars.size() ? 2 : 1 : 0, currentLength = 2;

        std::sort(hBars.begin(), hBars.end());
        std::sort(vBars.begin(), vBars.end());

        for(int i = 1; i < hBars.size(); ++i) {
            if(hBars[i - 1] == hBars[i] - 1) {
                ++currentLength;
            } else {
                maxWidth = std::max(maxWidth, currentLength);
                currentLength = 2;
            }
        }
        maxWidth = std::max(maxWidth, currentLength);

        currentLength = 2;

        for(int i = 1; i < vBars.size(); ++i) {
            if(vBars[i - 1] == vBars[i] - 1) {
                ++currentLength;
            } else {
                maxHeight = std::max(maxHeight, currentLength);
                currentLength = 2;
            }
        }
        maxHeight = std::max(maxHeight, currentLength);

        return std::pow(std::min(maxWidth, maxHeight), 2);
    }
};
