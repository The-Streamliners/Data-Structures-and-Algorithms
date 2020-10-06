import java.util.Scanner;

public class Smallest_number_with_sum_of_digits_as_N_and_divisible_by_10_pow_N {

    public static String fun1(int n)
    {
        String temp="";
        if(n==0)
            System.out.println(0);
        
        else if(n%9!=0)
            temp=temp+n%9;

        for (int i=1; i <=n/9; i++) {
            temp=temp+9;
        }

        for(int i=0;i<n;i++)
        {
            temp=temp+0;
        }

        return temp;
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        s.close();
        System.out.println(fun1(n));
    }
}
