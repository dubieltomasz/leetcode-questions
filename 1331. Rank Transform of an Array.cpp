class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        int l, r, m;
        std::set<int> s(arr.begin(), arr.end());
        std::vector<int> v(s.begin(), s.end());
        s.clear();

        for(int i = 0; i < arr.size(); ++i)
        {
            l = 0; r = v.size();

            while(l <= r)
            {
                m = (l+r)/2;

                if(arr[i] == v[m]) break;
                else if(v[m] < arr[i]) l = m+1;
                else r = m-1;
            }

            arr[i] = m+1;
        }

        return arr;
    }
};
