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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* nn = new TreeNode();
            nn->val = val;
            nn->left = root;
            return nn;
        }
        int lvl = 1;
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,lvl});
        while(!q.empty()){
            auto k = q.front();
            q.pop();
            TreeNode* node = k.first;
            int level = k.second;
            if(level==(depth - 1)){//2==2
                TreeNode* x = node->left;
                TreeNode* y = node->right;
                
                TreeNode* nn_left = new TreeNode();
                nn_left->val = val;
                
                TreeNode* nn_right = new TreeNode();
                nn_right->val = val;
                
                nn_left->left = x;
                nn_right->right = y;
                
                node->left = nn_left;
                node->right = nn_right;
            }
            
            if(node->left)q.push({node->left,level+1});
            if(node->right)q.push({node->right,level+1});
            
        }
        return root;
    }
};