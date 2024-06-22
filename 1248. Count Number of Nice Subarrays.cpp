class Solution {
public:
    int numberOfSubarrays(const vector<int>& nums, const int& k) {
        vector<int> v = {-1};
        int answer = 0;

        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] % 2) v.push_back(i);
        v.push_back(nums.size());

        if(v.size() / k == 0) return 0;

        for(int i = 1; i < v.size()-k; ++i)
            answer += (v[i]-v[i-1]) * (v[i+k]-v[i+k-1]);
        
        return answer;
    }
};
