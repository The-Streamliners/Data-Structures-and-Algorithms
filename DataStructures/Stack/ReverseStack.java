
/* Question

    You have been given two stacks that can store integers as the data. Out of the two given stacks,
    one is populated and the other one is empty. You are required to write a function that
    reverses the populated stack using the one which is empty.

    Sample Input :
    1 2 3 4 5 10

    Note:Here, 10 is at the top of the stack.

    Sample Output :
    10 5 4 3 2 1

    Note:Here, 1 is at the top of the stack.

 */

import java.util.Stack;

public class ReverseStack {

    // Time complexity : O(n**2)
    public static void reverseStack(Stack<Integer> input, Stack<Integer> extra) {

        int n = input.size();
        for (int i = 0; i < n; i++) {

            int temp = input.pop();

            // except temp transfer all element from input stack to extra stack
            for (int j = 0; j < n-i-1; j++) {
                int x = input.pop();
                extra.push(x);
            }

            // push temp into input stack
            input.push(temp);

            // transfer all element from extra stack to input stack
            for (int k = 0; k < n-i-1; k++) {
                int x = extra.pop();
                input.push(x);
            }

        }
    }

    public static void main(String[] args) {

        Stack<Integer> input = new Stack<>();
        Stack<Integer> extra = new Stack<>();
        int[] arr = {1, 2, 3, 4, 5};
        for (int i = 0; i < arr.length; i++) {
            input.push(arr[i]);
        }

        reverseStack(input, extra);

        while (!input.isEmpty()) {
            System.out.println(input.pop());
        }
    }
}
