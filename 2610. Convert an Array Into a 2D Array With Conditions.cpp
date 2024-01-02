class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        sort(begin(nums), end(nums));

        vector<vector<int>> arr{{nums[0]}};
        unsigned row = 0, countRows = 1;

        for(unsigned i = 1; i < nums.size(); ++i)
        {
            if(nums[i-1] == nums[i])
            {
                if(++row < countRows)
                {
                    arr[row].push_back(nums[i]);
                }
                else
                {
                    arr.push_back({});
                    arr[row].push_back(nums[i]);
                    ++countRows;
                }
            }
            else
            {
                row = 0;
                arr[row].push_back(nums[i]);
            }
        }

        return arr; 
    }
};
