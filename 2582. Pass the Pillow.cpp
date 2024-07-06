class Solution {
public:
    int passThePillow(const int& n, int time) {
        int i = 1;
        int r = 1;

        while(time--)
        {
            i += r;

            if(i == n || i == 1) r *= -1;
        }

        return i;
    }
};
