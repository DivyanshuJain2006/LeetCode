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
    vector<vector<int>>ans;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void nthOrder(TreeNode* root,int curr,int level,vector<int>&v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
      nthOrder(root->left,curr+1,level,v);
      nthOrder(root->right,curr+1,level,v);
    }
    void lOrder(TreeNode* root){
        if(root==NULL) return;
        int n = levels(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            nthOrder(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        lOrder(root);
        return ans;
    }
};