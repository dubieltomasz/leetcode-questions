class Solution {
public:
    std::string getDirections(TreeNode* root, const int& startValue, const int& destValue) {
        std::string pathToStart, pathToDest;
        
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        int i = 0;
        while(i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i])
            ++i;

        return std::string (pathToStart.size()-i, 'U') + pathToDest.substr(i, pathToDest.size()-i);
    }

private:
    bool findPath(TreeNode* node, const int& value, std::string& path)
    {
        if(!node) return false;
        else if(node->val == value) return true;
        else
        {
            path += "L";
            if(findPath(node->left, value, path)) return true;

            path.pop_back();

            path += "R";
            if(findPath(node->right, value, path)) return true;

            path.pop_back();

            return false;
        }
    }
};
