class Solution {
public:
    vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> v{};
        set<int> s1;
        set<int> s2;

        for(const int& num : nums1)
            s1.insert(num);

        for(const int& num : nums2)
            s2.insert(num);

        set<int>::iterator i1 = s1.begin(), i2 = s2.begin();

        while(i1 != s1.end() && i2 != s2.end())
        {
            if(*i1 == *i2)
            {
                v.push_back(*i1++);
                ++i2;
            }
            else if(*i1 > *i2) ++i2;
            else if(*i1 < *i2) ++i1;
        }

        return v;
    }
};
