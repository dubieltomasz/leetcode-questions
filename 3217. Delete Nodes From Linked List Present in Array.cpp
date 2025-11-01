class Solution {
public:
    ListNode* modifiedList(const std::vector<int>& nums, ListNode* head) {
        ListNode *pointer = new ListNode(0, head), *tmp = pointer;
        bool arr[100000] = {};

        for(const int& num : nums) {
            arr[num - 1] = true;
        }

        while(tmp->next != nullptr) {
            if(arr[tmp->next->val - 1]) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }

        tmp = pointer;
        pointer = pointer->next;
        delete tmp;

        return pointer;
    }
};
