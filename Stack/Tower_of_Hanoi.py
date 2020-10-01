#Contribiuted by Shyam Yadav [github/YA12SHYAM]
#implementing recusion solution of Tower of Hanoi in python

def solve_hanoi(n,from_rod,to_rod,use_rod):
  if(n==1):
    print("Move disk 1 from rod {} to_rod {}".format(from_rod,to_rod))
  else:
    #solve top n-1 disc from source rod to auxillary/Using rod
    solve_hanoi(n-1,from_rod,use_rod,to_rod)
    
    #Move remaining largest disc from Source rod to target rod
    print("Move disk {} from rod {} to rod {}".format(n,from_rod,to_rod))
    
    #solve n-1 disc from auxillary rod to target rod 
    solve_hanoi(n-1,use_rod,to_rod,from_rod)

def main():
  print("Enter the Number of disc")
  # the number of disc is n
  n=int(input())
  print()
  # Source rod is rod 'a',Target rod is rod 'b',Using/auxillary rod is rod 'c'
  solve_hanoi(n,'a','b','c')

if __name__ == "__main__":
  main()
