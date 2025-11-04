class Solution {
public:
    int minNumberOperations(const std::vector<int>& target) {
        int count = 0;

        for(int i = 1; i < target.size(); ++i) {
            if(target[i - 1] < target[i]) {
                count += target[i] - target[i - 1];
            }
        }

        return count + target[0];
    }
};
