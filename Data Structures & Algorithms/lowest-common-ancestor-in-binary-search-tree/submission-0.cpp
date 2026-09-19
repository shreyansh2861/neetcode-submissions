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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *h1=root,*h2=root;

        vector<TreeNode*> v1,v2;

        while(h1!=p){
            v1.push_back(h1);
            if(p->val>h1->val){
                h1=h1->right;
            }
            else{
                h1=h1->left;
            }
        }
        v1.push_back(h1);
        while(h2!=q){
            v2.push_back(h2);
            if(q->val>h2->val){
                h2=h2->right;
            }
            else{
                h2=h2->left;
            }
        }
        v2.push_back(h2);

        while(v1.size()>v2.size()){
            v1.pop_back();
        }
        while(v2.size()>v1.size()){
            v2.pop_back();
        }

        while(v1[v1.size()-1]!=v2[v2.size()-1]){
            v1.pop_back();
            v2.pop_back();
        }

        return v1[v1.size()-1];
    }
};
