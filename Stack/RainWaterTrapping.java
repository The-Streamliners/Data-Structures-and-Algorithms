import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * @author Hrithik Sharma (Coder481)
 */
public class RainWaterTrapping {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        print("Enter heights in positive integer with space:");
        String[] arr = sc.nextLine().split("\\s+");
        int size = arr.length;

        Integer[] maxL = new Integer[size];
        Integer[] maxR = new Integer[size];

        maxL[0] = Integer.parseInt(arr[0]);
        maxR[size-1] = Integer.parseInt(arr[size-1]);

        for (int i=1; i<size; i++){
            maxL[i] = Math.max(maxL[i-1], Integer.parseInt(arr[i]));

            int j = (size-1) - i;
            maxR[j] = Math.max(maxR[j+1], Integer.parseInt(arr[j]));
        }

        List<Integer> waterList = IntStream.range(0,size)
                .mapToObj(i -> Math.min(maxR[i], maxL[i]) - Integer.parseInt(arr[i]))
                .collect(Collectors.toList());

        int totalWater = waterList.stream().mapToInt(Integer::intValue).sum();

        print("Total water stored is: "+totalWater+" Unit");
    }

    private static void print(String s){
        System.out.print(s);
    }

}
