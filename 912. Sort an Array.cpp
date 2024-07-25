class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        func(nums, 0, nums.size()-1);

        return nums;
    }

private:
    void func(std::vector<int>& v, const int L, const int R)
    {
        int l = L, r = R, pivot = v[(L+R)/2];

        while(l <= r)
        {        
            while(v[l] < pivot)
                ++l;

            while(pivot < v[r])
                --r;

            if(l <= r)
            {
                int tmp = v[r];
                v[r] = v[l];
                v[l] = tmp;

                ++l;
                --r;
            }
        }

        if(L < r) func(v, L, r);
        if(l < R) func(v, l, R);
    }
};
