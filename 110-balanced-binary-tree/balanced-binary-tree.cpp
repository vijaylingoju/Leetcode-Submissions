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
    bool flag = true;
    int fun(TreeNode*root){
        if(!root)return 0;
        int l = fun(root->left);
        int r = fun(root->right);
        int diff = (l-r);
        if(diff<-1 or diff>1)flag= false;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {

        int temp = fun(root);
        return flag;
    }
};