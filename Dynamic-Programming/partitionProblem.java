class Solution{
     
// Returns true if arr[] can be partitioned in two subsets of equal sum, otherwise false
public static boolean findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for(i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    boolean[] part = new boolean[sum / 2 + 1];
 
    // Initialize the part array as 0
    for(i = 0; i <= sum / 2; i++)
    {
        part[i] = false;
    }
 
    // Fill the partition table in bottom up manner
    for(i = 0; i < n; i++)
    {
         
        // The element to be included in the sum cannot be greater than the sum
        for(j = sum / 2; j >= arr[i]; j--)
        {
             
            // Check if sum - arr[i] could be formed from a subset using elements before index i
            if (part[j - arr[i]] == true || j == arr[i])
                part[j] = true;
        }
    }
    return part[sum / 2];
}
 
// Driver code
public static void main(String[] args)
{
  Scanner scn = new Scanner(System.in);
  int n = scn.nextInt();
  int[] arr = new int[n];
  
  for(int i = 0; i<n; i++)
  {
    arr[i] = scn.nextInt();
  }
  // Function call
  if (findPartiion(arr, n) == true)
    System.out.println("Can be divided into two " + "subsets of equal sum");
  else
    System.out.println("Can not be divided into " + "two subsets of equal sum");
 }
}
