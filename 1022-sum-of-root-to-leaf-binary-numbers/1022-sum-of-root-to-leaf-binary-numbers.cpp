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
    void fun(TreeNode* root,vector<int> v){
    if(root == NULL) return;
    v.push_back(root->val);
    if(root->left == NULL && root->right == NULL){
        ans.push_back(v);
        return;
    }
    fun(root->left, v);
    fun(root->right, v);
    }
    int binaryToDecimal(vector<int>& binary) {
    int decimal = 0;

    for (int bit : binary) {
        decimal = decimal * 2 + bit;
    }

    return decimal;
}
    int sumRootToLeaf(TreeNode* root) {
        vector<int>v;
        fun(root,v);
        int answer = 0;
        for(int i=0;i<ans.size();i++){
            answer += binaryToDecimal(ans[i]);
        }
        return answer;
    }
};