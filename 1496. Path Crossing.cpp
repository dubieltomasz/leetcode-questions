class Solution {
public:
    bool isPathCrossing(string path) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<array<int, 2>> x;
        x.push_back({0,0});

        for(int i = 0; i < path.length(); ++i)       
        {
            switch(path[i])
            {
                case 'N':
                    x.push_back({x[i][0], x[i][1]-1});
                    break;
                case 'E':
                    x.push_back({x[i][0]+1, x[i][1]});
                    break;
                case 'S':
                    x.push_back({x[i][0], x[i][1]+1});
                    break;
                default:
                    x.push_back({x[i][0]-1, x[i][1]});
                    break;
            }

            for(int j = 0; j < x.size()-1; ++j)
                if(x[j] == x[i+1])
                    return true;
        }

        return false;
    }
};
