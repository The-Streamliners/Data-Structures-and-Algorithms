class solution {
    static int i;
 
    // Recursive Function to find product of elements at k-th level
    static int productAtKthLevel(
        String tree, int k, int level){
 
        if (tree.charAt(i++) == '(') {
 
            // if subtree is null, just like if root == null
            if (tree.charAt(i) == ')')
                return 1;
 
            int product = 1;
 
            // Consider only level k node to be part of the product
            if (level == k)
                product = tree.charAt(i) - '0';
 
            // Recur for Left Subtree
            ++i;
            int leftproduct = productAtKthLevel(tree, k, level + 1);
 
            // Recur for Right Subtree
            ++i;
            int rightproduct = productAtKthLevel(tree, k, level + 1);
 
            // Taking care of ')' after left and right subtree
            ++i;
            return product * leftproduct* rightproduct;
        }
        return Integer.MIN_VALUE;
    }
 
    // Driver Code
    public static void main(String[] args)
    {
      Scanner scn = new Scanner(System.in);
      String tree = scn.next();
      int k = scn.nextInt;
      i = 0;
      System.out.print(productAtKthLevel(tree, k, 0));
    }
}
