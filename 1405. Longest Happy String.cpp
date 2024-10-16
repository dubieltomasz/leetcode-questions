class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        int x = 0, y = 0, z = 0;
        std::string answer = "";

        while(true)
        {
            if(a > 0 && a >= b && a >= c && x < 2)
            {
                answer += 'a';
                --a;
                
                ++x;
                y = 0;
                z = 0;
            }
            else if(b > 0 && b >= c && y < 2)
            {
                answer += 'b';
                --b;

                x = 0;
                ++y;
                z = 0;
            }
            else if(c > 0 && z < 2)
            {
                answer += 'c';
                --c;

                x = 0;
                y = 0;
                ++z;
            }
            else if(a > 0 && x < 2)
            {
                answer += 'a';
                --a;
                
                ++x;
                y = 0;
                z = 0;
            }
            else if(b > 0 && y < 2)
            {
                answer += 'b';
                --b;

                x = 0;
                ++y;
                z = 0;
            }
            else break;
        }

        return answer;
    }
};
