class Solution {
public:
    int totalMoney(const int &n) {
        int money{};

        for(int day = 0; day < n; ++day)
            money += day/7+day%7+1;
        
        return money;
    }
};
