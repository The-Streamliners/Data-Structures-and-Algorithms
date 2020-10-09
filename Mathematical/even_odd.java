import java.util.Scanner;

public class even_odd{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        if(a%2==0)
            System.out.print("Even");
        else
            System.out.println("Odd");
        s.close();
    }
}
