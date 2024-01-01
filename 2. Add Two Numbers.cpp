/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        ListNode* l3 = new ListNode();
        ListNode* l4 = l3;
        int x = 0;

        while(l1 != nullptr || l2 != nullptr || x != 0)
        {
            if(l1 != nullptr) {x += l1->val; l1 = l1->next;}
            if(l2 != nullptr) {x += l2->val; l2 = l2->next;}

            ListNode* tmp = new ListNode(x % 10);
            x /= 10;

            l4->next = tmp;
            l4 = l4->next;
        }

        return l3->next;
    }
};
