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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            int lvl = q.front().second;
            int prev = lvl%2 ? INT_MAX:INT_MIN;
            for(int i = 0; i < n ; i++){
                TreeNode* nn = q.front().first;
                q.pop();
                if(lvl%2==0){
                    if(nn->val%2==0 || nn->val<=prev)return false;
                }
                else{
                    if(nn->val%2!=0 || nn->val>=prev)return false;
                }
                prev=nn->val;
                if(nn->left){
                    q.push({nn->left,lvl+1});
                }
                if(nn->right){
                    q.push({nn->right,lvl+1});
                }   
            }
        }
        return true;
    }
};