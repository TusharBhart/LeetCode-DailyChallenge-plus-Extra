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
    void dfs(TreeNode* root, TreeNode* prnt, unordered_set<TreeNode*> &vis, int &ans) {
        if(!root) return;
        dfs(root -> left, root, vis, ans);
        dfs(root -> right, root, vis, ans);

        if(vis.find(root -> left) == vis.end() || vis.find(root -> right) == vis.end() || 
           (!prnt && vis.find(root) == vis.end())) {
            vis.insert(root -> left);
            vis.insert(root -> right);
            vis.insert(root);
            vis.insert(prnt);
            ans++;
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> vis;
        vis.insert(NULL);

        int ans = 0;
        dfs(root, NULL, vis, ans);
        return ans;
    }
};