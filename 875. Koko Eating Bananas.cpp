class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, const int& h) {
        int l = 1, r = 1e+9, m, currTime;

        while(l <= r)
        {
            m = l+(r-l)/2;
            currTime = 0;

            for(const int& pile : piles)
            {
                currTime += pile/m;

                if(pile % m) ++currTime;

                if(currTime > h) break;
            }

            currTime <= h ? r = m-1 : l = m+1;
        }

        return l;
    }
};
