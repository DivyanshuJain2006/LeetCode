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
    int count = 0;
    int average(TreeNode* root,int& sum,int& n){
        if(root==NULL) return 0;
        sum+=root->val;
        n++;
        average(root->left,sum,n);
        average(root->right,sum,n);
        return sum/n;
    }
    void fun(TreeNode* root){
        if(root==NULL) return;
        int sum=0;
        int n=0;
        if(root->val==average(root,sum,n)) count++;
        fun(root->left),fun(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return count;
    }
};