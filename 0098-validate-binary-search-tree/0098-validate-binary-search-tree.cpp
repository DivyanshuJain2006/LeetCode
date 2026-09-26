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
    void inorder(TreeNode* root,TreeNode*& prev,bool& flag){
        if(root==NULL) return;
        if(flag==false) return;
        inorder(root->left,prev,flag);
        if(prev!=NULL){
            if(root->val<=prev->val){
                flag=false;
                return;
            }
        }
        prev=root;
        inorder(root->right,prev,flag);
    }
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        TreeNode* temp = NULL;
        inorder(root,temp,flag);
        return flag;
    }
};