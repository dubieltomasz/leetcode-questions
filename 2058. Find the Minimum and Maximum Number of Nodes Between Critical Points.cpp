class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> indices;
        ListNode* tmp = head->next;
        int ll = head->val, i = 2;

        while(tmp->next)
        {
            if(ll < tmp->val && tmp->val > tmp->next->val)
                indices.push_back(i);

            if(ll > tmp->val && tmp->val < tmp->next->val)
                indices.push_back(i);
            
            ll = tmp->val;
            tmp = tmp->next;
            ++i;
        }
        
        if(indices.size() < 2) return {-1, -1};

        int minVal = INT_MAX;

        for(int i = 1; i < indices.size(); ++i)
            minVal = std::min(minVal, indices[i]-indices[i-1]);

        return {minVal, indices.back()-indices.front()};
    }
};
