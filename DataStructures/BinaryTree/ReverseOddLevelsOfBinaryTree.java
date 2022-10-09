package BinaryTree;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Hrithik Sharma (Coder481)
 */
class ReverseOddLevelsOfBinaryTree{

    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        TreeNode three = new TreeNode(3);
        TreeNode five = new TreeNode(5);
        TreeNode eight = new TreeNode(8);
        TreeNode trtn = new TreeNode(13);
        TreeNode twnOne = new TreeNode(21);
        TreeNode trtyFr = new TreeNode(34);

        root.left = three;
        root.right = five;

        three.left = eight;
        three.right = trtn;

        five.left = twnOne;
        five.right = trtyFr;

        System.out.println("Before reversing");
        printInOrderTree(root);
        root = reverseOddLevels(root);

        System.out.println("After reversing");
        printInOrderTree(root);
    }

    private static void printInOrderTree(TreeNode root){
        if(root == null) return;
        System.out.println(root.val);
        printInOrderTree(root.left);
        printInOrderTree(root.right);
    }


    public static TreeNode reverseOddLevels(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        tra(list, root, 0);
        modify(list, root, 0);
        return root;
    }
    private static void modify(List<List<Integer>> res, TreeNode root, int level){
        if(root == null) return;

        // Odd level
        if((level%2) != 0){

            // Modify root data with last item of list, and then remove the last item
            List<Integer> lvlArr = res.get(level);
            root.val = lvlArr.get(lvlArr.size()-1);
            lvlArr.remove(lvlArr.size()-1);
        }

        modify(res,root.left,level+1);
        modify(res,root.right,level+1);
    }

    // generate list with level-order items
    private static void tra(List<List<Integer>> res, TreeNode root, int level){
        if(root == null) return;

        if(level >= res.size())
            res.add(new ArrayList<>());

        res.get(level).add(root.val);
        tra(res,root.left,level+1);
        tra(res,root.right,level+1);
    }

    static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode() {}
        TreeNode(int val) { this.val = val; }
        public TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}