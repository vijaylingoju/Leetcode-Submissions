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
    void fun(TreeNode*root, vector<int>&ds){
        if(!root)return;
        fun(root->left,ds);
        ds.push_back(root->val);
        fun(root->right,ds);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ds;
        fun(root,ds);
        return ds;
    }
};