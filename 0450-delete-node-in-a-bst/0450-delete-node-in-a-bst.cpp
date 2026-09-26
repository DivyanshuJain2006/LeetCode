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
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right!=NULL){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            //case1;
            if(root->left==NULL && root->right==NULL) return NULL;
            //case2
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }
            //case3;
            if(root->right!=NULL && root->left!=NULL){
                TreeNode* pred = iop(root);
                root->val=pred->val;
                root->left = deleteNode(root->left,pred->val);
            }
        }
        else if(root->val>key) root->left = deleteNode(root->left,key);
        else root->right = deleteNode(root->right,key);
        return root;
    }
};