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
    void fun(TreeNode* root, vector<int>&ans){
        if(!root)return;
        if(!root->left and !root->right)ans.push_back(root->val);
        fun(root->left,ans);
        fun(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>l1;
        vector<int>l2;
        fun(root1,l1);
        fun(root2,l2);
        if(l1.size()!=l2.size())return false;
        for(int i = 0; i < l1.size(); i++)if(l1[i]!=l2[i])return false;
        return true;
    }
};