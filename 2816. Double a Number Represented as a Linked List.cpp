class Solution {
private:
    bool func(ListNode* node)
    {
        if(node)
        {
            node->val = node->val*2 + (func(node->next) ? 1 : 0);
            
            if(node->val > 9)
            {
                node->val %= 10;
                return true;
            }
        }

        return false;
    }
    
public:
    ListNode* doubleIt(ListNode* head) {
        if(func(head)) return new ListNode(1, head);
        else return head;
    }
};
