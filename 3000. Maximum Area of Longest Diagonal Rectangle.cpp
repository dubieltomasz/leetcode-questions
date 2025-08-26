class Solution {
public:
    int areaOfMaxDiagonal(const std::vector<std::vector<int>>& dimensions) {
        int area = 0;
        double longestDiagonal = 0;

        for(const std::vector<int>& v : dimensions){
            double tmp = std::sqrt(std::pow((double)v[0], 2) + std::pow(v[1], 2));

            if(tmp > longestDiagonal){
                longestDiagonal = tmp;
                area = v[0] * v[1];
            } else if(tmp == longestDiagonal){
                area = std::max(area, v[0] * v[1]);
            }
        }

        return area;
    }
};
