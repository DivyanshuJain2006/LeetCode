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
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void nthLevel(TreeNode* root,int curr,int level,vector<int>&v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
        }
        nthLevel(root->left,curr+1,level,v);
        nthLevel(root->right,curr+1,level,v);
    }
    void nthLevelRev(TreeNode* root,int curr,int level,vector<int>&v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
        }
        nthLevelRev(root->right,curr+1,level,v);
        nthLevelRev(root->left,curr+1,level,v);
    }
    void lOrder(TreeNode* root,vector<vector<int>>&ans){
        int n = level(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            if(i%2!=0) nthLevel(root,1,i,v);
            else nthLevelRev(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        lOrder(root,ans);
        return ans;
    }
};