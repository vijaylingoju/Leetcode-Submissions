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
    // bool flag = true;
    int fun(TreeNode*root){
        if(!root)return 0;

        int l = fun(root->left);
        if(l==-1)return -1;
        int r = fun(root->right);
        if(r==-1)return -1;

        int diff = abs(l-r);
        if(diff>1)return -1;

        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {

        return fun(root)!=-1;
    }
};