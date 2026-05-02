class Solution {
public:
    int rotatedDigits(int n) {
        int answer = 0;

        for(int i = 1; i <= n; ++i) {
            bool b = 0;
            int tmp = i;

            while(tmp) {
                switch(tmp % 10) {
                case 2:
                case 5:
                case 6:
                case 9:
                    b = 1;
                    break;
                case 3:
                case 4:
                case 7:
                    tmp = 0;
                    b = 0;
                }

                tmp /= 10;
            }

            answer += b;
        }

        return answer;
    }
};
