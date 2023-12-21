class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> xs;
        for(vector<int> &point : points) xs.push_back(point[0]);

        sort(begin(xs), end(xs));

        int n = 0;

        for(unsigned int i = 1; i < xs.size(); ++i)
            if(xs[i] - xs[i-1] > n)
                n = xs[i] - xs[i-1];

        return n;
    }
};
