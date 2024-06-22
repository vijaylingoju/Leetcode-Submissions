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
    vector<vector<int>> bfs(TreeNode* root){
        if(!root)return {};
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>qq;
        qq.push({root,0});
        while(!qq.empty()){
            auto it = qq.front();
            TreeNode* node = it.first;
            int level =it.second;
            qq.pop();
            if (level >= ans.size()) {
            ans.resize(level + 1);
        }
            ans[level].push_back(node->val);
            if(node->left){
                qq.push({node->left,level+1});

            }
            if(node->right){
                qq.push({node->right,level+1});
            }
        }
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};