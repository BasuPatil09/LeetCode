class Solution {
private:
    int height(TreeNode* root, int& maxDiameter) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = height(root->left, maxDiameter);
        int rightHeight = height(root->right, maxDiameter);
        int currentDiameter = leftHeight + rightHeight;
        maxDiameter = max(maxDiameter, currentDiameter);
        return max(leftHeight, rightHeight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        height(root, maxDiameter);
        return maxDiameter;
    }
};