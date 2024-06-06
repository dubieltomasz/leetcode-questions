class Solution {
public:
    bool isNStraightHand(vector<int>& hand, const int& groupSize) {
        if(hand.size() % groupSize != 0) return false;
        if(groupSize == 1) return true;

        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); ++i)
        {
            if(hand[i] != -1)
            {
                int x = hand[i]+1;
                hand[i] = -1;
                int k = 1;

                for(int j = i+1; j < hand.size() && k < groupSize; ++j)
                {
                    if(hand[j] == x)
                    {
                        hand[j] = -1;
                        ++x;
                        ++k;
                    }
                }

                if(k != groupSize) return false;
            }
        }

        return true;
    }
};
