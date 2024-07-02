/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    int fun(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)return 0;
        int left = fun(root->left,p,q);
        int right = fun(root->right,p,q);
        int count = 0;
        if(root==p or root==q){
            count+=1;
        }
        if((count+left+right)==2 and ans==NULL)ans = root;
        return left+right+count;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        int temp =  fun(root,p,q);
        return ans;
    }
};