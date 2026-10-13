class Solution {
public:
    TreeNode* insert(vector<int>& preorder, int& i, int bound) {
        if (i >= preorder.size() || preorder[i] > bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = insert(preorder, i, root->val);
        root->right = insert(preorder, i, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return insert(preorder, i, INT_MAX);
    }
};