class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int coun1{}, pCoun1 = 1, coun2{}, pCoun2{}, tmpI0{};

        for(int i = 0; i < s.size(); ++i)
        {
            int tmpI1 = int(s[i])-48;
            int coun1{}, coun2{};

            if(tmpI1 != 0)
                coun1 = pCoun1 + pCoun2;
            else
                coun1 = 0;

            tmpI0 *= 10;
            tmpI0 += tmpI1;

            if(tmpI0 > 9 && tmpI0 < 27)    
                coun2 = pCoun1;

            tmpI0 %= 10;
            pCoun1 = coun1;
            pCoun2 = coun2;
        }

        return pCoun1 + pCoun2;
    }
};
