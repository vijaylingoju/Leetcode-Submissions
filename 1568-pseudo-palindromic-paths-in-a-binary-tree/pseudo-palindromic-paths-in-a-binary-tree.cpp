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
    int ans = 0;

    void fun(TreeNode *root, int check){
        if(!root)return;
        check^=(1<<root->val);
        if(!root->left and !root->right){
            ans+= (!check or !(check&(check - 1))) ;
            return;
        }
        
        fun(root->left,check);
        fun(root->right,check);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        fun(root,0);
        return ans;
    }
};