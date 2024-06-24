class NumArray {
public:
    NumArray(const vector<int>& nums) {
        v.reserve(nums.size()+1);
        v.push_back(0);

        for(const int& num : nums)
            v.push_back(v.back() + num);
    }
    
    int sumRange(const int& left, const int& right) {
        return v[right+1] - v[left];
    }

private:
    vector<int> v;
};
