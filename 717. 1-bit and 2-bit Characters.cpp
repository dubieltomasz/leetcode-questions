class Solution {
public:
    bool isOneBitCharacter(const std::vector<int>& bits) {
        if(bits.size() == 1 || bits[bits.size()-2] == 0) {
            return true;
        }

        int i = 0;
        bool answer = false;

        while(i < bits.size()) {
            if(bits[i]) {
                i += 2;
                answer = false;
            } else {
                i++;
                answer = true;
            }
        }

        return answer;
    }
};
