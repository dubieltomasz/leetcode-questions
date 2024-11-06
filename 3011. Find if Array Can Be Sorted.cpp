class Solution {
public:
    bool canSortArray(const std::vector<int>& nums) {
        int setBits = countSetBits(nums.front()), lastMaxNum = 0, curMaxNum = nums.front(), curMinNum = nums.front();

        for(const int& num : nums)
        {
            if(countSetBits(num) != setBits)
            {
                if(lastMaxNum > curMinNum)
                    return false;

                setBits = countSetBits(num);
                lastMaxNum = curMaxNum;
                curMaxNum = num;
                curMinNum = num;
            }
            else
            {
                curMaxNum = std::max(curMaxNum, num);
                curMinNum = std::min(curMinNum, num);
            }
        }
        
        if(lastMaxNum > curMinNum)
            return false;

        return true;
    }

private:
    int countSetBits(int n)
    {
        int count = 0;
        
        while(n)
        {
            if(n & 1)  ++count;

            n >>= 1;
        }

        return count;
    }
};
