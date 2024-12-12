class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        std::make_heap(gifts.begin(), gifts.end());

        while(k--)
        {
            int tmp = gifts.front();
            std::pop_heap(gifts.begin(), gifts.end());
            gifts.pop_back();
            
            gifts.push_back(std::sqrt(tmp));
            std::push_heap(gifts.begin(), gifts.end());
        }

        return accumulate(gifts.begin(), gifts.end(), 0ll);
    }
};
