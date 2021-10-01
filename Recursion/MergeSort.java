

public class MergeSort {

    public static void merge(int[] arr1, int[] arr2, int[] arr){

        int i = 0, j = 0, k = 0;

        while (i < arr1.length && j < arr2.length){

            if (arr1[i] < arr2[j]){
                arr[k] = arr1[i];
                i++;
                k++;
            }
            else {
                arr[k] = arr2[j];
                j++;
                k++;
            }
        }

        while (i < arr1.length){
            arr[k] = arr1[i];
            i++;
            k++;
        }

        while (j < arr2.length){
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    public static void mergeSort(int[] input){

        // Base Case
        if (input.length <= 1){
            return;
        }

        // divide input array in two parts
        int mid = input.length / 2;
        int[] arr1 = new int[mid];
        int[] arr2 = new int[input.length - mid];

        // part 1 : from 0 to mid-1
        for (int i = 0; i < mid; i++){
            arr1[i] = input[i];
        }

        // part 2 : mid to length of input array
        for (int j = mid; j < input.length; j++){
            arr2[j-mid] = input[j];
        }

        // call merge sort in both part of the array
        mergeSort(arr1);
        mergeSort(arr2);

        // merge them in input array after sorting
        merge(arr1, arr2, input);
    }

    public static void main(String[] args) {

        int[] arr = {2,1,5,7,3,9};
        mergeSort(arr);
        for (int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
}
