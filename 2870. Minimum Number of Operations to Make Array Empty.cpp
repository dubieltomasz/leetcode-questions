class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> um;

        for(int num : nums)
            um[num] += 1;

        int n = 0;

        for(auto i : um)
        {
            while(i.second >= 3 && i.second != 4)
            {
                i.second -= 3;
                ++n;
            }
            
            while(i.second % 2 == 0 && i.second)
            {
                i.second -= 2;
                ++n;
            }

            if(i.second == 1) return -1;
        }

        return n;
    }
};
