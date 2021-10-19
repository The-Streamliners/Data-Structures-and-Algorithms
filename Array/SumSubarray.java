package Array;

public class SumSubarray {
    public static void main(String[] args) {
        System.out.println("Sum of subarrays: " + subArray(arr.length));
    }
    static int[] arr = new int[]{1,2,3};
    static  int subArray(int n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                for(int k = i; k <= j; k++){
                   sum += arr[k];
                }
            }
        }
        return sum;
    }
}
