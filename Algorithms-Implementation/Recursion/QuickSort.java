
/* Question

    Sort an array A using Quick Sort.
    Change in the input array itself. So no need to return or print anything.

    Input format :
    Line 1 : Integer n i.e. Array size
    Line 2 : Array elements (separated by space)

    Output format :
    Array elements in increasing order (separated by space)

    Sample Input 1 :
    6
    2 6 8 5 4 3

    Sample Output 1 :
    2 3 4 5 6 8

 */

public class QuickSort {

    public static int partition(int[] input, int si, int ei){

        // pick the pivot element
        int pivotElement = input[si];

        // count of element less than pivotElement
        int smallNumCount = 0;
        for (int i = si + 1; i <= ei; i++){
            if (input[i] < pivotElement){
                smallNumCount++;
            }
        }

        // put pivotElement at correct position
        int temp = input[si + smallNumCount];
        input[si + smallNumCount] = pivotElement;
        input[si] = temp;

        // move all the element less than pivot to left
        // and all the element greater than pivot to right
        int i = si;
        int j = ei;
        while (i < j){
            if (input[i] < pivotElement){
                i++;
            }
            else if (input[j] >= pivotElement){
                j--;
            }else{
                int x = input[i];
                input[i] = input[j];
                input[j] = x;
                i++;
                j--;
            }
        }

        // return pivot index
        return si + smallNumCount;
    }

    public static void quickSort(int[] input, int startIndex, int lastIndex){

        // Base Case
        if (startIndex >= lastIndex){
            return;
        }
        // find out pivot index
        int pivotIndex = partition(input, startIndex, lastIndex);
        // call quick sort in both part of array
        quickSort(input, startIndex, pivotIndex-1);
        quickSort(input, pivotIndex+1, lastIndex);

    }

    public static void main(String[] args) {

        int[] arr = {2,1,5,7,3,9};
        quickSort(arr, 0, arr.length-1);
        for (int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
}
