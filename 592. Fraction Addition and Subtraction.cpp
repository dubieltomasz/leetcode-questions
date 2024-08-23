class Solution {
public:
    std::string fractionAddition(const std::string& expression) {
        std::vector<int> numenators, denominators;
        bool positive = true;
        int number = 0;

        for(int i = 0; i < expression.size();)
        {
            if(expression[i] == '-')
            {
                positive = false;
                ++i;
            }
            else if(expression[i] == '+')
            {
                positive = true;
                ++i;
            }

            while('0' <= expression[i] && expression[i] <= '9')
            {
                number = number * 10 + (int(expression[i])-'0');
                ++i;
            }

            numenators.push_back((positive ? number : -number));
            number = 0;
            ++i;

            while('0' <= expression[i] && expression[i] <= '9')
            {
                number = number * 10 + (int(expression[i])-'0');
                ++i;
            }

            denominators.push_back(number);
            number = 0;
        }

        for(int i = 0; i < numenators.size(); ++i)
        {
            add(numenators[i], denominators[i]);
        }

        if(b == 0) return "0/1";
        else if(a > -1) return std::to_string(a) + "/" + std::to_string(b);
        else return "-" + std::to_string(abs(a)) + "/" + std::to_string(b);
    }

private:
    int a = 0, b = 0;

    void add(int c, int d)
    {
        if(c == 0 || d == 0)
        {
            return;
        }

        if(a == 0 && b == 0)
        {
            a = c;
            b = d;
            return;
        }

        int nww = b/NWD(b, d)*d;
        a *= nww/b;
        c *= nww/d;
        b = nww;
        d = nww;
        a += c;

        if(a == 0)
        {
            b = 0;
            return;
        }

        int g = NWD(abs(a), b);
        a /= g;
        b /= g;
    }

    int NWD(int a, int b)
    {
        int x;

        while(b)
        {
            x = b;
            b = a % b;
            a = x;  
        }

        return a;
    }
};
