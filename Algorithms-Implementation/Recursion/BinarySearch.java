public class BinarySearch {

    public static int binarySearch(int[] arr, int x, int startIndex, int lastIndex){

        // Base Case :- if x is not present in arr
        if (startIndex > lastIndex){
            return -1;
        }

        int midIndex = (startIndex + lastIndex)/2;
        // if x is less than middle element
        if (arr[midIndex] > x){
            int smallOutput = binarySearch(arr, x, startIndex, midIndex-1);
            return smallOutput;
        }
        // if x is greater than middle element
        else if (arr[midIndex] < x){
            int smallOutput = binarySearch(arr, x, midIndex + 1, lastIndex);
            return smallOutput;
        }
        // else x is equal to medium element
        else {
            return midIndex;
        }
    }

    public static void main(String[] args) {

        int[] arr = {1, 3, 5, 7, 9};
        int x = 3;
        int index = binarySearch(arr, x, 0, arr.length-1);
        System.out.println(index);
    }
}
