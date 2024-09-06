class Solution {
public:
    ListNode* modifiedList(const std::vector<int>& nums, ListNode* head) {
        ListNode newHead(0, head), *tmp = &newHead;
        std::set<int> s(nums.begin(), nums.end());

        while(tmp->next)
        {
            if(s.find(tmp->next->val) != s.end())
                tmp->next = tmp->next->next;
            else tmp = tmp->next;
        }

        return newHead.next;
    }
};
