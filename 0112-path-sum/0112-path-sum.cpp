/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    void helper(TreeNode* root, int targetSum,int sum){
        if (root == NULL) return;
        sum+=root->val;
        if(root->left==NULL and root->right==NULL){
            if(sum==targetSum){ flag = true;}
            return;
        }
        
        helper(root->left,targetSum,sum);
        helper(root->right,targetSum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        int sum=0;
        helper(root,targetSum,sum);
        return flag;
    }
};