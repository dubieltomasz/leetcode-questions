class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) { 
        std::vector<int> arr;
        std::queue<TreeNode*> q;
        int maxInRow, n;

        if(root) q.push(root);

        while(!q.empty())
        {
            maxInRow = INT_MIN;
            n = q.size();

            while(n--)
            {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);

                maxInRow = std::max(maxInRow, q.front()->val);
                q.pop();
            }

            arr.push_back(maxInRow);
        }

        return arr;
    }
};
