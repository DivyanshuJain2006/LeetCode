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
    vector<string>result;
    void dfs(TreeNode* root,string s){
        if(root==NULL) return;
        string a = to_string(root->val);
        if(root->left==NULL and root->right==NULL){
            s+=a;
            result.push_back(s);
            return;
        }
        dfs(root->left,s+a+"->");
        dfs(root->right,s+a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        dfs(root,s);
        
        return result;
    }
};