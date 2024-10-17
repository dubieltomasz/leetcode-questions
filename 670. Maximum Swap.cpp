class Solution {
public:
    int maximumSwap(const int num) {
        std::string n = to_string(num);
        std::string n1 = n;
        int i = 0;

        std::sort(n.rbegin(), n.rend());

        while(i < n.size())
        {
            if(n[i] != n1[i]) break;

            ++i;
        }

        if(i < n.size())
        {
            char m = n1[i];
            int r = i;

            for(int j = i + 1; j < n1.size(); ++j)
            {
                if(n1[j] >= m)
                {
                    m = n1[j];
                    r = j;
                }
            }

            std::swap(n1[i], n1[r]);
        }

        return stoi(n1);    
    }
};
