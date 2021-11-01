class Solution {
  
static int countDP(int dist)
{
        // Create the array of size 3.
        int []ways = new int[3];
        int n = dist;
         
         
        // Initialize the bases cases
        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;
         
        // Run a loop from 3 to n Bottom up approach to fill the array
        for(int i=3 ;i<=n ;i++)
            ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3] + ways[(i-3)%3];
         
        return ways[n%3];
}
  
// driver program
public static void main(String arg[])
    {
      Scanner scn = new Scanner(System.in);
      int dist = scn.nextInt();
      System.out.print(countDP(dist));
    }
}
