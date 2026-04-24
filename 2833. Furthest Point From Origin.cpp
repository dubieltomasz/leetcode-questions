class Solution {
public:
    int furthestDistanceFromOrigin(const std::string& moves) {
        int dist = 0, blanks = 0;

        for(const char& move : moves) {
            switch(move) {
                case 'L':
                    --dist;
                    break;
                case 'R':
                    ++dist;
                    break;
                default:
                    ++blanks;
                    break;
            }
        }

        return std::abs(dist) + blanks;
    }
};
