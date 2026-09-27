class Solution {
public:
    void trim(TreeNode* root, int lo, int hi) {
        if (root == NULL) return;

        // Only the dummy has to handle the root itself being out of range
        if (root->val == INT_MAX) {
            while (root->left != NULL) {
                if (root->left->val < lo)
                    root->left = root->left->right;
                else if (root->left->val > hi)
                    root->left = root->left->left;
                else
                    break;
            }
        }

        // For a normal node, left can only be < lo
        while (root->left != NULL) {
            if (root->left->val < lo)
                root->left = root->left->right;
            else
                break;
        }

        // For a normal node, right can only be > hi
        while (root->right != NULL) {
            if (root->right->val > hi)
                root->right = root->right->left;
            else
                break;
        }

        trim(root->left, lo, hi);
        trim(root->right, lo, hi);
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;

        trim(dummy, low, high);

        return dummy->left;
    }
};