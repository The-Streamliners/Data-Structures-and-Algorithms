/*Check Whether a number is Duck Number or not*/

import java.util.Scanner;

public class Check_duck_number
{
    public static void main(String[] args)
    {
    
        int r, n, num;
        boolean flag=false;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter number=");
        n = input.nextInt();
        num = n;

        while (num > 0)
        {
            r = num % 10;
            if(r==0)
            {
                flag=true;
            }
            num = num / 10;
        }
        if(flag)
        {
            System.out.println("Duck Number");
        }
        else
        {
            System.out.println("Not Duck Number");
        }
        
    }
}