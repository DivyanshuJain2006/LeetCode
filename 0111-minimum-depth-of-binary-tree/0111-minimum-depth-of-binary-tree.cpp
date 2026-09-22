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
    int ans = INT_MAX;
    void fun(TreeNode* root,int x){
        if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL) {
            x+=1;
            ans = min(ans,x);
            return;
        }
        x+=1;
        fun(root->left,x),fun(root->right,x);
    }
    int minDepth(TreeNode* root) { 
        if(root==NULL) return 0; 
        int x = 0;
        fun(root,x);
        return ans;
    }
};