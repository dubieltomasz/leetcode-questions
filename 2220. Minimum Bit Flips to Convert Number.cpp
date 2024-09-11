class Solution {
public:
    int minBitFlips(int start, int goal) {
        int answer = 0;

        while(start || goal)
        {
            answer += start&1 ^ goal&1;

            start >>= 1;
            goal >>= 1;
        }
        
        return answer;
    }
};
