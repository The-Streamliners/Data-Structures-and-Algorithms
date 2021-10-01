import java.util.*;
public class evenOdd{

    public static String isEvenOdd(int n){
        return n % 2 == 0 ? "even" : "odd";
    }

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(isEvenOdd(n));
        sc.close();
    }
}
