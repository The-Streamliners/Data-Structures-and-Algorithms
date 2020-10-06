import java.util.Scanner;

public class extracting_max_num_value{
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        String a=s.next();
        String res="";
        int max=0;
        int flag=0;
        for(int i=0;i<a.length()-1;i++)
        {
            int res1=0;
            if(flag==1)
                res="";
            if(Character.isDigit(a.charAt(i)))
            {
                res=res+a.charAt(i);
                if(Character.isDigit(a.charAt(i+1)))
                    flag=0;
                else 
                {
                    flag=1;
                    res1=Integer.parseInt(res);
                }
            }

            if(i==a.length()-1)
                res=res+a.charAt(a.charAt(a.length()-1));
                
            
            if(flag==1)
            {
                if(max<res1)
                    max=res1;
            }
        }

        System.out.println(max);
        s.close();
    }
}