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
    vector<int>merge(vector<int>&v1,vector<int>&v2){
        int m = v1.size(), n = v2.size();
        vector<int>ans;
        int i = 0;
        int j = 0;
        while(i<m and j<n){
            if(v1[i]<=v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        if(i==m) while(j<n){ans.push_back(v2[j]); j++;}
        if(j==n) while(i<m){ans.push_back(v1[i]); i++;}
        return ans;
    }
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        vector<int> ans = merge(v1,v2);
        return ans;
    }
};