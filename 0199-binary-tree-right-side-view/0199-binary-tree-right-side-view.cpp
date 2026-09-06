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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void nthLevel(TreeNode* root,int curr,int level,vector<int>&v){
        if(root==NULL) return;
        if(curr==level){
            v[curr] = (root->val);
            return;
        }
        nthLevel(root->left,curr+1,level,v);
        nthLevel(root->right,curr+1,level,v);
    }
    vector<int> lOrder(TreeNode* root){
        int n = levels(root);
        vector<int>v(n);
        for(int i=0;i<n;i++){
            nthLevel(root,0,i,v);
        }
        return v;
    }
    vector<int> rightSideView(TreeNode* root) {
      return  lOrder(root);
         
    }
};