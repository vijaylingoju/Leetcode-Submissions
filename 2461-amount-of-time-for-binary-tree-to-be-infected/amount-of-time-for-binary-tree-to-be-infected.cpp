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
    int ans;
    void constructGraph(TreeNode* root,vector<vector<int>>&adj){
        if(!root)return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        constructGraph(root->left,adj);
        constructGraph(root->right,adj);
    }

    void bfs(int start, vector<vector<int>>&adj,vector<int>&vis){
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int x = q.front();
                q.pop();
                vis[x]=1;
                for(int i = 0; i < adj[x].size(); i++){
                    if(vis[adj[x][i]]!=1)q.push(adj[x][i]);
                }
            }
            ans+=1;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        ans=0;
        vector<int>vis(100001);
        vector<vector<int>>adj(100001);
        constructGraph(root,adj);
        bfs(start,adj,vis);
        return ans-1;
    }
};