class Solution {
public:
    int nthUglyNumber(const int n) {
        std::vector<int> v(n+1, 1);
        int i2 = 1, i3 = 1, i5 = 1, tmpi2, tmpi3, tmpi5, tmp;

        for(int i = 2; i < n+1; ++i)
        {
            tmpi2 = v[i2]*2;
            tmpi3 = v[i3]*3;
            tmpi5 = v[i5]*5;

            tmp = std::min(tmpi2, std::min(tmpi3, tmpi5));

            v[i] = tmp;

            if(tmp == tmpi2) ++i2;
            if(tmp == tmpi3) ++i3;
            if(tmp == tmpi5) ++i5;
        }

        return v.back(); 
    }
};
