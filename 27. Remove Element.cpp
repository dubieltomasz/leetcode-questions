class Solution {
public:
    int removeElement(vector<int>& nums, const int& val) {
        int k = 0;

        for(const int& i : nums)
            if(i != val) nums[k++] = i;

        return k;
    }
};
