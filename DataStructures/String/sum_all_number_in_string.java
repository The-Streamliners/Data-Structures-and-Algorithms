import java.util.Scanner;

public class sum_all_number_in_string
{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        String a=s.next();
        int sum=0;
        for(int i=0;i<a.length();i++)
        {
            if(Character.isDigit(a.charAt(i)))
            {
                sum+=a.charAt(i)-48;
            }
        }

        System.out.println(sum);
        s.close();
    }
}