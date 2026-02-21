class Solution {
private:
    bool isPrime(const int value) {
        if(value < 2) {
            return false;
        }

        for(int i = 2; i < value; ++i) {
            if(value % i == 0) {
                return false;
            }
        }

        return true;
    }
public:
    int countPrimeSetBits(int left, const int right) {
        int answer = 0;

        while(left <= right) {
            if(isPrime(std::bitset<32>(left++).count())) {
                ++answer;
            }
        }

        return answer;
    }
};
