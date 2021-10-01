import javafx.util.Pair;

/**
 * @author Hrithik Sharma (Coder481)
 *
 * Finding Minimum and Maximum values in an array using Divide and Conquer Approach
 *
 */
public class Find_MinMax {

    public static void main(String[] args) {

        int[] arr = {17,3,5,18,20,50,-1,-19};
        int s = 0;
        int e = arr.length - 1;

        Pair<Integer,Integer> res = solve(arr,s,e);
        System.out.println("Max:"+res.getKey()+" Min:"+res.getValue());
    }

    private static Pair<Integer, Integer> solve(int[] arr, int s, int e) {

        if (s==e){
            return new Pair<>(arr[s], arr[e]);
        }
        else if (s+1 == e){
            return new Pair<>(Math.max(arr[s], arr[e]), Math.min(arr[s], arr[e]));
        }

        int mid = s + (e-s)/2;

        Pair<Integer, Integer> p1 = solve(arr,s,mid);
        Pair<Integer, Integer> p2 = solve(arr,mid+1,e);

        return new Pair<>(Math.max(p1.getKey(), p2.getKey()), Math.min(p1.getValue(), p2.getValue()));
    }


}
