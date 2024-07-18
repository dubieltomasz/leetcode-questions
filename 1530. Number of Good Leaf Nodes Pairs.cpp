class Solution {
public:
    int countPairs(TreeNode* root, const int& distance) {
        return postOrder(root, distance).back();
    }

private:
    std::vector<int> postOrder(TreeNode* currentNode, const int& distance)
    {
        if(!currentNode) return vector<int>(12);
        else if(!currentNode->left && !currentNode->right)
            return {1,0,0,0,0,0,0,0,0,0,0,0};
        else
        {
            std::vector<int> left = postOrder(currentNode->left, distance);
            std::vector<int> right = postOrder(currentNode->right, distance);

            std::vector<int> current(12);

            for(int i = 0; i < 10; ++i)
                current[i+1] = left[i] + right[i];
            
            current.back() += left[11] + right[11];

            for(int i = 0; i <= distance; ++i)
                for(int j = 0; j <= distance; ++j)
                    if(i + j + 2 <= distance)
                        current.back() += left[i] * right[j];

            return current;
        }
    }
};
