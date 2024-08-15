class Solution {
public:
    bool lemonadeChange(const std::vector<int>& bills) {
        int five = 0, ten = 0;

        for(const int& bill : bills)
        {
            switch(bill)
            {
                case 5:
                    ++five;
                    break;
                case 10:
                    if(five)
                    {
                        ++ten;
                        --five;
                    }
                    else return false;
                    break;
                default:
                    if(ten && five)
                    {
                        --ten;
                        --five;
                    }
                    else if(five > 2) five -= 3;
                    else return false;
                    break;
            }
        }

        return true;
    }
};
