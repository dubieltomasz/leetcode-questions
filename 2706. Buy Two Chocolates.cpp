class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = INT_MAX, b = INT_MAX;

        for(int price : prices)
        {
            if(price < a)
            {
                b = a;
                a = price;
            }
            else if(price < b)
                b = price;
        }

        return money<a+b?money:money-a-b;
    }
};
