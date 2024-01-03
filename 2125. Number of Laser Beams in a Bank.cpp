class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(bank.size() < 2) return 0;

        vector<int> arr{};

        for(string row : bank)
        {
            int secDev = 0;

            for(char cell : row)
                if(cell == '1') ++secDev;

            if(secDev) arr.push_back(secDev);
        }

        int n = 0;

        for(size_t i = 1; i < arr.size(); ++i)
            n += arr[i-1] * arr[i];

        return n;
    }
};
