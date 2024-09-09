class Solution {
public:
    std::vector<std::vector<int>> spiralMatrix(const int m, const int n, ListNode* head) {
        std::vector<std::vector<int>> answer(m, std::vector<int> (n, -1));
        int row = 0, column = -1;

        while(head)
        {
            while(++column < n && answer[row][column] == -1 && head)
            {
                answer[row][column] = head->val;
                head = head->next;
            }

            --column;

            while(++row < m && answer[row][column] == -1 && head)
            {
                answer[row][column] = head->val;
                head = head->next;
            }

            --row;

            while(--column > -1 && answer[row][column] == -1 && head)
            {
                answer[row][column] = head->val;
                head = head->next;
            }

            ++column;

            while(--row > -1 && answer[row][column] == -1 && head)
            {
                answer[row][column] = head->val;
                head = head->next;
            }

            ++row;
        }

        return answer;
    }
};
