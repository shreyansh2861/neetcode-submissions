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
    boolean val = true;
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }

        int l = traverse(root.left);
        int r = traverse(root.right);

        if(Math.abs(l-r)>1){
            val=false;
        }

        return val;
    }

    public int traverse(TreeNode root){
        if(root==null){
            return 0;
        }

        int l = traverse(root.left);
        int r = traverse(root.right);

        if(Math.abs(l-r)>1){
            val=false;
        }
        return Math.max(l,r)+1;
    }
}
