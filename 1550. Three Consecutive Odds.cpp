class Solution {
public:
    bool threeConsecutiveOdds(const vector<int>& arr) {
        int count = 0;

        for(const int& number : arr)
        {
            if(number % 2)
            {
                if(++count == 3) return true;
            }
            else count = 0;
        }
        
        return false;
    }
};
