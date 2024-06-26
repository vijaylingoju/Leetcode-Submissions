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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*,unsigned int>>q;
        q.push_back({root,0});
        unsigned int ans = 0;
        while(!q.empty()){
            unsigned int n = q.size();
            // cout<<n<<endl;
            unsigned int f = q.front().second;
            unsigned int b =  q.back().second;
            cout<<f<<" "<<b<<endl;
            ans = max(ans,(b - f+1));
            for(int j = 0; j < n; j++){
                auto k = q.front();
                q.pop_front();
                unsigned int i = k.second;
                if(k.first->left){
                    q.push_back({k.first->left,2*i+1});

                }
                if(k.first->right){
                    q.push_back({k.first->right, 2*i+2});
                }
            }

        }
        return ans;
    }
};