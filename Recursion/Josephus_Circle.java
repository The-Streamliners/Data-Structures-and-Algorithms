import java.util.ArrayList;
import java.util.List;

/**
 * @author Hrithik Sharma (Coder481)
 */
public class Josephus_Circle {

    public static void main(String[] args) {

        int n = 40, k = 7;

        List<Integer> arr = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            arr.add(i);
        }

        k = k-1;

        solve(arr,k,0);
    }

    private static void solve(List<Integer> arr, int k, int index) {

        if (arr.size() == 1){
            System.out.println(arr.get(0));
            return;
        }

        index = (index + k) % arr.size();
        arr.remove(index);

        solve(arr, k, index);

    }


}
