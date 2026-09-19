/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int d = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null){
            return 0;
        }

        int l = traverse(root.left,1);
        int r = traverse(root.right,1);

        return Math.max(d,l+r);
    }

    public int traverse(TreeNode root, int h){
        if(root==null){
            return 0;
        }

        int l = traverse(root.left,h+1);
        int r = traverse(root.right,h+1);
        
        d = Math.max(d,l+r);

        return Math.max(l,r)+1;
    }
}
