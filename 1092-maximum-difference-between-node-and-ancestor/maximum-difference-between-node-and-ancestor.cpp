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
    void fun(TreeNode* root, int mn, int mx){
        if(!root)return;
        if(mx!=(-1e9) and mn!=1e9){
            int val1 = abs(mn - (root->val));
            int val2 = abs(mx - (root->val));
            ans = max(ans,max(val1,val2));
        }
        fun(root->left,min(root->val,mn),max(root->val,mx));
        fun(root->right,min(root->val,mn),max(root->val,mx));
        
    }
    int maxAncestorDiff(TreeNode* root) {
        fun(root,1e9,-1e9);
        return ans;
    }
};