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
    int cnt=1;
    int goodNodes(TreeNode* root) {
        traverse(root->left,root->val);
        traverse(root->right,root->val);

        return cnt;
    }
    void traverse(TreeNode* root,int h){
        if(root==NULL){
            return;
        }

        if(root->val>=h){
            cnt++;
            h=root->val;
        }

        traverse(root->left,h);
        traverse(root->right,h);
    }
};
