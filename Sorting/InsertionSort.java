
//This code is contributed by Anand4756

//This program ia an implementation of insertion sort algorithm
class InsertionSort{       
public static void main(String args[]){

int[] a = {1,99,5,56,2,53,23,54,79};   //this is an array which we want to sort
for(int i=1;i<a.length;i++){        //here we are iterating through the whole array 
int temp = a[i];            //as the index changes i.e. i we are storing it in a variable called temp
int j=i;              
while(j>0 && a[j-1]>temp){        //here it is a while loop to check if the element is greater than 0 and if value in temp variable is less than previous value
  a[j]=a[j-1];        // if the condition becomes true, the value of previous element is stored in enxt element.
  j=j-1;                //we are decreasing the value of j by 1
}
a[j]=temp;                  //the value of temp is stored
}
for(int i=0;i<a.length;i++){          //this for loop is to print sorted array
System.out.println(a[i]);
}
}
}
