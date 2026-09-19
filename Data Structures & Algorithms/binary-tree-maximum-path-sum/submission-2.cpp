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
    int m=INT_MIN;
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return m;
    }

    int traverse(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int l=traverse(root->left);
        int r=traverse(root->right);

        int i = root->val + (l>0?l:0) + (r>0?r:0);

        cout<<i<<" ";

        m = max(m,i);

        return root->val + max(0,max(l,r));
    }
};
